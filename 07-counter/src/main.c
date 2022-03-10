#include <gtk/gtk.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *txt_counter;
    GtkWidget *bt_counter;
} widgets_t;

int main (int argc, char *argv[])
{
    GtkBuilder *builder;

    widgets_t *widgets = g_slice_new (widgets_t);

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    widgets->window = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    widgets->bt_counter = GTK_WIDGET (gtk_builder_get_object (builder, "bt_counter"));
    widgets->txt_counter = GTK_WIDGET (gtk_builder_get_object (builder, "txt_counter"));

    gtk_entry_set_text (GTK_ENTRY (widgets->txt_counter), "0");

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

void on_bt_counter_clicked(GtkButton *bt_counter, void *data)
{
    widgets_t *w = (widgets_t *)data;

    static int value = 0;
    char buffer[1024] = {0};

    snprintf (buffer, 1024, "%d", ++value);

    gtk_entry_set_text (GTK_ENTRY (w->txt_counter), buffer);
}