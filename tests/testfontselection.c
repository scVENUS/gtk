/* testfontselection.c
 * Copyright (C) 2011 Alberto Ruiz <aruiz@gnome.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include <gtk/gtk.h>


int
main (int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *hbox;
  GtkWidget *fontsel;
  
  gtk_init (NULL, NULL);
    
  fontsel = gtk_font_selection_new ();

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (window, 600, 600);
  hbox = gtk_hbox_new (FALSE, 6);
  gtk_container_add (GTK_CONTAINER (window), hbox);

  g_object_ref (gtk_font_selection_get_size_list (GTK_FONT_SELECTION (fontsel)));
  g_object_ref (gtk_font_selection_get_family_list (GTK_FONT_SELECTION (fontsel)));
  g_object_ref (gtk_font_selection_get_face_list (GTK_FONT_SELECTION (fontsel)));

  gtk_container_add (GTK_CONTAINER (hbox), gtk_font_selection_get_size_list (GTK_FONT_SELECTION (fontsel)));
  gtk_container_add (GTK_CONTAINER (hbox), gtk_font_selection_get_family_list (GTK_FONT_SELECTION (fontsel)));
  gtk_container_add (GTK_CONTAINER (hbox), gtk_font_selection_get_face_list (GTK_FONT_SELECTION (fontsel)));
  gtk_container_add (GTK_CONTAINER (hbox), fontsel);

  gtk_widget_show_all (window);

  gtk_main ();

  gtk_widget_destroy (window);

  return 0;
}