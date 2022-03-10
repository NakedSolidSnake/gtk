#include <gtk/gtk.h>
#include <stdio.h>

typedef struct 
{
    GtkWidget *window;
    GtkWidget *ck_rice;
    GtkWidget *ck_beans;
    GtkWidget *ck_salad;
    GtkWidget *ck_meat;
    GtkWidget *ck_chicken;
    GtkWidget *ck_fries;
    GtkWidget *bt_order;
} widgets_t;

int main (int argc, char *argv[])
{
    GtkBuilder *builder;

    widgets_t *widgets = g_slice_new (widgets_t);

    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();

    gtk_builder_add_from_file (builder, "glade/window.glade", NULL);

    widgets->window     = GTK_WIDGET (gtk_builder_get_object (builder, "window"));
    widgets->ck_rice    = GTK_WIDGET (gtk_builder_get_object (builder, "ck_rice"));
    widgets->ck_beans   = GTK_WIDGET (gtk_builder_get_object (builder, "ck_beans"));
    widgets->ck_salad   = GTK_WIDGET (gtk_builder_get_object (builder, "ck_salad"));
    widgets->ck_meat    = GTK_WIDGET (gtk_builder_get_object (builder, "ck_meat"));
    widgets->ck_chicken = GTK_WIDGET (gtk_builder_get_object (builder, "ck_chicken"));
    widgets->ck_fries   = GTK_WIDGET (gtk_builder_get_object (builder, "ck_fries"));
    widgets->bt_order   = GTK_WIDGET (gtk_builder_get_object (builder, "bt_order"));

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

void on_ck_fries_toggled   (GtkToggleButton *ck_fries,   void *data)
{
    printf ("Fritas adicionado ao prato.\n");
} 

void on_ck_chicken_toggled (GtkToggleButton *ck_chicken, void *data)
{
    printf ("Frango adicionado ao prato.\n");
}

void on_ck_meat_toggled    (GtkToggleButton *ck_meat,    void *data)
{
    printf ("Carne adicionado ao prato.\n");
}

void on_ck_salad_toggled   (GtkToggleButton *ck_salad,   void *data)
{
    printf ("Salada adicionado ao prato.\n");
}

void on_ck_beans_toggled   (GtkToggleButton *ck_beans,   void *data)
{
    printf ("Feijão adicionado ao prato.\n");
}

void on_ck_rice_toggled    (GtkToggleButton *ck_rice,    void *data)
{
    printf ("Arroz adicionado ao prato.\n");
}

void on_bt_order_clicked   (GtkButton       *bt_order,   void *data)
{
    widgets_t *w = (widgets_t *)data;
    GtkWidget *dialog;
    char buffer [1024] = {0};
    const char *template = "Seu Prato tem: ";
    snprintf (buffer, 1024, "%s", template);

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_rice)))
    {
        strncat (buffer, " Arroz", 1024 - strlen (buffer));
    }

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_beans)))
    {
        strncat (buffer, " Feijão", 1024 - strlen (buffer));
    }

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_salad)))
    {
        strncat (buffer, " Salada", 1024 - strlen (buffer));
    }

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_meat)))
    {
        strncat (buffer, " Carne", 1024 - strlen (buffer));
    }

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_chicken)))
    {
        strncat (buffer, " Frango", 1024 - strlen (buffer));
    }

    if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (w->ck_fries)))
    {
        strncat (buffer, " Fritas", 1024 - strlen (buffer));
    }


    if (strlen (buffer) == strlen (template))
    {
        dialog = gtk_message_dialog_new (GTK_WINDOW (w->window),
                                         GTK_DIALOG_MODAL,
                                         GTK_MESSAGE_INFO,
                                         GTK_BUTTONS_OK,
                                         "%s",
                                         "Por favor selecione alguma coisa para comer.");
    }
    else 
    {
        dialog = gtk_message_dialog_new (GTK_WINDOW (w->window),
                                         GTK_DIALOG_MODAL,
                                         GTK_MESSAGE_INFO,
                                         GTK_BUTTONS_OK,
                                         "%s",
                                         buffer);
    }

    gtk_dialog_run (GTK_DIALOG (dialog));
    gtk_widget_destroy (dialog);
}
