#include <gtk/gtk.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *bt_press;
} widgets_t;

int main (int argc, char *argv[])
{
    GtkBuilder *builder;

    widgets_t *widgets = g_slice_new (widgets_t);

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    widgets->window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    widgets->bt_press = GTK_WIDGET (gtk_builder_get_object (builder, "bt_press"));

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

void on_bt_press_clicked (GtkButton *bt_press, void *data)
{
    widgets_t *widgets = (widgets_t *)data;

    char *message = "Hello World";

    GtkWidget *dialog = gtk_message_dialog_new (GTK_WINDOW (widgets->window),
                                                GTK_DIALOG_MODAL,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK, 
                                                "%s",
                                                message);

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}