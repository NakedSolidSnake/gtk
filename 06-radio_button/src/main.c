#include <gtk/gtk.h>
#include <stdio.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *rb_white;
    GtkWidget *rb_black;
    GtkWidget *rb_yellow;
    GtkWidget *rb_blue;
    GtkWidget *rb_red;
    GtkWidget *bt_confirm;
} widgets_t;

int main (int argc, char *argv[])
{
    GtkBuilder *builder;

    widgets_t *widgets = g_slice_new (widgets_t);

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    widgets->window     = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    widgets->rb_white   = GTK_WIDGET (gtk_builder_get_object (builder, "rb_white"));
    widgets->rb_black   = GTK_WIDGET (gtk_builder_get_object (builder, "rb_black"));
    widgets->rb_yellow  = GTK_WIDGET (gtk_builder_get_object (builder, "rb_yellow"));
    widgets->rb_blue    = GTK_WIDGET (gtk_builder_get_object (builder, "rb_blue"));
    widgets->rb_red     = GTK_WIDGET (gtk_builder_get_object (builder, "rb_red"));
    widgets->bt_confirm = GTK_WIDGET (gtk_builder_get_object (builder, "bt_confirm"));

    gtk_builder_connect_signals (builder, widgets);

    g_object_unref (builder);

    gtk_widget_show (widgets->window);

    gtk_main ();

    g_slice_free (widgets_t, widgets);

    return 0;
}


void on_window_destroy (void)
{
    gtk_main_quit ();
}

void on_bt_confirm_clicked (GtkButton *bt_confirm, void *data)
{
    widgets_t *w = (widgets_t *)data;
    GtkWidget *dialog;
    char buffer [1024] = {0};
    const char *template = "A sua camisa vai ser confeccionada na cor %s ";;

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->rb_white)))
    {
        snprintf (buffer, 1024, template, "Branca");
    }

    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->rb_black)))
    {
        snprintf (buffer, 1024, template, "Preta");
    }

    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->rb_yellow)))
    {
        snprintf (buffer, 1024, template, "Amarela");
    }

    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->rb_blue)))
    {
        snprintf (buffer, 1024, template, "Azul");
    }

    else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->rb_red)))
    {
        snprintf (buffer, 1024, template, "Vermelha");
    }


    dialog = gtk_message_dialog_new (GTK_WINDOW (w->window),
                                         GTK_DIALOG_MODAL,
                                         GTK_MESSAGE_INFO,
                                         GTK_BUTTONS_OK,
                                         "%s",
                                         buffer);    

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}