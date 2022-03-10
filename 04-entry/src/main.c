#include <gtk/gtk.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *bt_confirm;
    GtkWidget *txt_name;
    GtkWidget *lb_name;
} widgets_t;

int main (int argc, char *argv[])
{
    GtkBuilder *builder;

    widgets_t *widgets = g_slice_new (widgets_t);

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    widgets->window     = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    widgets->bt_confirm = GTK_WIDGET (gtk_builder_get_object (builder, "bt_confirm"));
    widgets->txt_name   = GTK_WIDGET (gtk_builder_get_object (builder, "txt_name"));
    widgets->lb_name    = GTK_WIDGET (gtk_builder_get_object (builder, "lb_name"));

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

    const gchar *name = gtk_entry_get_text (GTK_ENTRY (w->txt_name));
    gtk_label_set_text (GTK_LABEL (w->lb_name), name);
}

void on_txt_name_changed (GtkEditable *txt_name, void *data)
{
    widgets_t *w = (widgets_t *)data;

    gtk_label_set_text (GTK_LABEL (w->lb_name), "");
}