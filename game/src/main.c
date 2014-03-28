#include <gtk/gtk.h>

#define WINDOW_WIDTH     500
#define WINDOW_HEIGHT    500

#define BTN_WIDTH       200
#define BTN_HEIGHT      50

static void button_test()
{
    printf("I'm testing button\n");
}

static void button_create (GtkWidget* hbox, const char* label, GCallback func, gint x, gint y)
{
    GtkWidget* btn_test = gtk_button_new_with_label (label); //BUTTON'S CREATED
    gtk_widget_set_size_request(btn_test, BTN_WIDTH, BTN_HEIGHT); //SIZE CONTROL
    gtk_fixed_put( GTK_FIXED(hbox), btn_test , x, y);
    g_signal_connect( G_OBJECT (btn_test), "clicked", func, NULL);
}


int main(int argc, char* argv[])
{
    GtkWidget* window;
    GtkWidget* vbox;
    GtkWidget* frame;
    GtkWidget* selfStart;
    GtkWidget* makeRoom;
    GtkWidget* CloseBtn;
    GtkWidget* table;
    GtkWidget* wins;
    /*INITIALIZE */
    gtk_init(&argc, &argv);

    /* DIALOG'S ADDED */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size( GTK_WINDOW (window), WINDOW_WIDTH, WINDOW_HEIGHT);
    gtk_window_set_title( GTK_WINDOW (window), "omok");

    gtk_container_set_border_width( GTK_CONTAINER(window), 15);

    g_signal_connect( G_OBJECT (window), "destroy",
            G_CALLBACK(gtk_main_quit), NULL);

	/*vertical box */
	vbox = gtk_vbox_new(TRUE, 1);
	
	selfStart = gtk_button_new_with_label("SelfStart");
	makeRoom = gtk_button_new_with_label("Make Room");
	CloseBtn = gtk_button_new_with_label("CLOSE");

    g_signal_connect( G_OBJECT (CloseBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL);


    gtk_box_pack_start( GTK_BOX(vbox), selfStart, TRUE, TRUE, 0);
    gtk_box_pack_start( GTK_BOX(vbox), makeRoom, TRUE, TRUE, 0);
    gtk_box_pack_start( GTK_BOX(vbox), CloseBtn, TRUE, TRUE, 0);
    
    /*create table */
    table = gtk_table_new( 5, 4, TRUE);
    gtk_table_set_row_spacings( GTK_TABLE (table), 2);
    gtk_table_set_col_spacings( GTK_TABLE (table), 2);
    gtk_table_attach_defaults( GTK_TABLE(table), vbox, 0, 1, 1, 4); 

    wins = gtk_text_view_new();
    gtk_text_view_set_editable( GTK_TEXT_VIEW(wins), FALSE);
    gtk_text_view_set_cursor_visible( GTK_TEXT_VIEW(wins), FALSE);
    gtk_table_attach( GTK_TABLE(table), wins, 1,4,0,5, GTK_FILL | GTK_EXPAND, GTK_FILL | GTK_EXPAND, 1, 1);

    gtk_container_add(GTK_CONTAINER (window), table);
    

    gtk_widget_show_all (window);
        
    gtk_main();
    
    return 0;
}
