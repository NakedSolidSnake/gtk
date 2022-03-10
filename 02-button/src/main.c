#include <gtk/gtk.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *bt_press;
    GtkWidget *lb_message;
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
    widgets->lb_message = GTK_WIDGET (gtk_builder_get_object (builder, "lb_message"));

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

    gtk_label_set_text (GTK_LABEL (widgets->lb_message), "Hello World");
}   