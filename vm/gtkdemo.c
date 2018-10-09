#include <gtk/gtk.h>


int		main(int ac, char **av) {
	GtkWidget *main_win = NULL;
	GtkBuilder *builder = NULL;
	gchar	*filename = NULL;
	GError *error = NULL;

	gtk_init(&ac, &av);

	builder = gtk_builder_new();
	filename =  g_build_filename("corewar.glade", NULL);
	gtk_builder_add_from_file(builder, filename, &error);
	g_free(filename);

	main_win = GTK_WIDGET(gtk_builder_get_object (builder, "main_win"));
	g_signal_connect(G_OBJECT(main_win), "destroy", (GCallback)gtk_main_quit, NULL);
	gtk_widget_show_all(main_win);
	gtk_main();
}
