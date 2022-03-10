#include "view.h"
#include <gtk/gtk.h>
#include <string.h>

void view_set_text (void *object, const char *text);
void view_run (void *object);
bool view_graphic_init (view_t *view);

bool view_init (view_t *view)
{
    bool status = true;

    if (view != NULL)
    {
        memset (view, 0, sizeof (view_t));

        view->base.object = view;

        view->base.set_text = view_set_text;
        view->base.run = view_run;

        status = true;
    }

    return status;
}

bool view_open (view_t *view, view_args_t *args)
{
    bool status = false;

    if (view != NULL && args != NULL)
    {
        view->controller_base = args->controller_base;
        view->argc = args->argc;
        view->argv = args->argv;

        status = view_graphic_init (view);
    }

    return status;
}

bool view_close (view_t *view)
{
    bool status = true;

    if (view != NULL)
    {
        g_slice_free (widgets_t, view->widgets);
        memset (view, 0, sizeof (view_t));
        status = true;
    }

    return status;
}

void view_set_text (void *object, const char *text)
{
    view_t *view = (view_t *)object;
    gtk_entry_set_text (GTK_ENTRY (view->widgets->txt_counter), text);
}

void view_run (void *object)
{
    view_t *view = (view_t *)object;
    gtk_widget_show (view->widgets->window);
    gtk_main ();
}

bool view_graphic_init (view_t *view)
{
    GtkBuilder *builder;

    view->widgets = g_slice_new (widgets_t);

    gtk_init (&view->argc, &view->argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    view->widgets->window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    view->widgets->bt_counter = GTK_WIDGET (gtk_builder_get_object (builder, "bt_counter"));
    view->widgets->txt_counter = GTK_WIDGET (gtk_builder_get_object (builder, "txt_counter"));

    gtk_builder_connect_signals (builder, view);

    g_object_unref (builder); 

    return true; 
}

void on_window_destroy (void)
{
    gtk_main_quit ();
}

void on_bt_counter_clicked(GtkButton *bt_counter, void *data)
{
    view_t *view = (view_t *)data;
    view->controller_base->on_click (view->controller_base->object);    
}