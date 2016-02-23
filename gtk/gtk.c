#include <gtk/gtk.h>


static gboolean expose_event(GtkWidget *widget, GdkEventExpose *event)
{
  

  GdkGC *black_gc = widget->style->black_gc;
  GdkGC *white_gc = widget->style->white_gc;
  
//  gdk_draw_arc(widget->window, white_gc, TRUE, 0,0, 50,50, 64*0,64*360);
//  gdk_draw_arc(widget->window, black_gc, FALSE,0,0, 50,50, 64*0,64*360);

 // gdk_draw_arc(widget->window, black_gc, TRUE, 60,0, 50,50, 64*0,64*360);
//  gdk_draw_arc(widget->window, white_gc, FALSE,60,0, 50,50, 64*0,64*360);

	gdk_draw_arc(widget->window,black_gc,FALSE,25,55,330,330,64*0,64*360);

	
	gdk_draw_rectangle(widget->window,black_gc,TRUE,100,100,150,250);
	gdk_draw_rectangle(widget->window,black_gc,TRUE,220,70,20,40);

	gdk_draw_rectangle(widget->window,white_gc,TRUE,120,120,110,120);

//	Gtklabel *label = new gtk_label_new_with_mnemonic ("CAUTION");
	
//	char *str = new char[];
//	*str = "Dangerous";	
//	void gtk_label_set_text (GtkLabel *label,const gchar *str);
	

	gdk_draw_line(widget->window,black_gc,80,80,280,370);
	gdk_draw_line(widget->window,black_gc,280,80,80,370);

//	gdk_draw_arc(widget->window,bl	
	
//	printf("DANGER \n");

 // gdk_draw_rectangle(widget->window,white_gc,TRUE, 0,60, 50,50);
//  gdk_draw_rectangle(widget->window,black_gc,FALSE,0,60, 50,50);

//  gdk_draw_rectangle(widget->window,black_gc,TRUE, 60,60, 50,50);
//  gdk_draw_rectangle(widget->window,white_gc,FALSE,60,60, 50,50);

//  gdk_draw_line(widget->window,white_gc, 140,10,140,100);
//  gdk_draw_line(widget->window,black_gc, 150,10,150,100);

  return TRUE;
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window),500,500);
    //g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(G_OBJECT(window), "expose_event", G_CALLBACK(expose_event), NULL);
    gtk_widget_show(window);
    gtk_main();    
    return 0;
}
