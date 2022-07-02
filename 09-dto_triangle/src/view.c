#include <gtk/gtk.h>
#include <view.h>
#include <string.h>

static triangle_dto_t view_get_triangle_dto (void *object);
static void view_set_triangle_result (void *object, const char *message);
static bool view_run (void *object);
static void view_graphic_init (view_t *view, view_args_t *args);

bool view_init (view_t *view)
{
    bool status = false;

    if (view != NULL)
    {
        memset (view, 0, sizeof (view_t));

        view->base.object = view;
        view->base.get_triangle_dto = view_get_triangle_dto;
        view->base.set_triangle_result = view_set_triangle_result;
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
        view->con = args->con;
        view_graphic_init (view, args);
        
        status = true;
    }

    return status;
}

bool view_close (view_t *view)
{
    g_slice_free (view_widgets_t, view->vw);
    return true;
}

static triangle_dto_t view_get_triangle_dto (void *object)
{
    triangle_dto_t dto;
    view_t *v = (view_t *)object;

    dto.side_a = (char *)gtk_entry_get_text (GTK_ENTRY (v->vw->txt_side_a));
    dto.side_b = (char *)gtk_entry_get_text (GTK_ENTRY (v->vw->txt_side_b));
    dto.side_c = (char *)gtk_entry_get_text (GTK_ENTRY (v->vw->txt_side_c));

    return dto;
}

static void view_set_triangle_result (void *object, const char *message)
{
    view_t *v = (view_t *)object;
    gtk_label_set_text (GTK_LABEL (v->vw->lb_resul), message);
}

static bool view_run (void *object)
{
    view_t *v = (view_t *)object;
    gtk_widget_show (v->vw->window);
    gtk_main ();
    return true;
}

static void view_graphic_init (view_t *view, view_args_t *args)
{
    GtkBuilder *builder;

    view->vw = g_slice_new (view_widgets_t);
    
    gtk_init (&args->argc, &args->argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    view->vw->window = GTK_WIDGET (gtk_builder_get_object (builder, "main_window"));
    view->vw->lb_resul = GTK_WIDGET (gtk_builder_get_object (builder, "lb_resul"));
    view->vw->bt_submit = GTK_WIDGET (gtk_builder_get_object (builder, "bt_submit"));
    view->vw->txt_side_a = GTK_WIDGET (gtk_builder_get_object (builder, "txt_side_a"));
    view->vw->txt_side_b = GTK_WIDGET (gtk_builder_get_object (builder, "txt_side_b"));
    view->vw->txt_side_c = GTK_WIDGET (gtk_builder_get_object (builder, "txt_side_c"));

    gtk_builder_connect_signals (builder, view);

    g_object_unref (builder);
}

void on_main_window_destroy (void)
{
    gtk_main_quit ();
}

void on_txt_side_changed (GtkEditable *txt_side_a, void *data)
{
    view_t *v = (view_t *)data;
    v->con->on_change (v->con->object);
}

 void on_bt_submit_clicked (GtkButton *bt_submit, void *data)
 {
    view_t *v = (view_t *)data;
    v->con->on_submit (v->con->object);
 }