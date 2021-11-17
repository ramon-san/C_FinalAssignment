#include "defEncuestar.h"

node *makeQueue(node *pt, node info);
void printQueue(node *pt);
void browseNode(node *pt, char *question);

void closeTheApp(GtkWidget *windowBrowse, gpointer empty);
void clickCall(GtkWidget *bCall, gpointer handler);
void clickZip(GtkWidget *bZip, gpointer handler);
void clickID(GtkWidget *bID, gpointer handler);
void clickUpdate(GtkWidget *bUpdate, gpointer handler);
void clickPrev(GtkWidget *bPrev, gpointer handler);
void clickConsult(GtkWidget *bConsult, gpointer handler);
void clickQuestion(GtkWidget *bQuestion, gpointer handler);
void clickNext(GtkWidget *bNext, gpointer handler);
void hideZip(GtkWidget *bwSZip, gpointer handler);
void searchZip(GtkWidget *bwZip, gpointer handler);
void moveNext(GtkWidget *bNext, gpointer handler);
void movePrev(GtkWidget *bPrev, gpointer handler);
void hideConsult(GtkWidget *bwConsult, gpointer handler);
void changeQuest(GtkWidget *bwQuestion, gpointer handler);
void clickB1(GtkWidget *b1, gpointer handler);
void clickB2(GtkWidget *b2, gpointer handler);
void clickB3(GtkWidget *b3, gpointer handler);
void clickB4(GtkWidget *b4, gpointer handler);
void clickBDel(GtkWidget *bDelete, gpointer handler);
void clickBUp(GtkWidget *bAdd, gpointer handler);
void clickCUp(GtkWidget *bwUpdate, gpointer handler);
void clickSID(GtkWidget *bwSID, gpointer handler);
void clickNID(GtkWidget *bwID, gpointer handler);

/*
* @file encuestar.c
*
* @brief El program es un interfaz gráfico para que personal de un call center pueda hacer llamadas y reportar datos.
*
* @author Miguel Meza y Ramón Orraca
* @date 01/11/2020
*
*/
int main(int argc, char *argv[]){
   GtkWidget *vbox, *hboxAns, *hboxData, *hboxSearch, *hboxMove, *vbZip, *vbSZip, *hbSZip, *vbConsult, *hbConsult, *hbConsult1, *hbConsult2, *hbConsult3, *hbConsult4;
   GtkWidget *vbQuestion, *hbQuest1, *hbQuest2, *hbQuest3, *vbCall, *hbCall1, *hbCall2,*vbUpdate, *hbUpdate, *vbNewS, *hbNew1, *hbNew2, *hbNew3, *hbNew4, *hbNew5, *hbNew6;
   GtkWidget *lCID, *lCPhone, *lCMail, *lCStat, *lCAddress, *lCZip, *lCName, *bDelete, *bAdd, *lCID1, *lCPhone1, *lCMail1, *labelChoose, *bRetID, *vbID, *vbSID;
   elements handler;
   char line[300];
   FILE *fp;
   node temp, *start;

   start = NULL;
   fp = fopen("pregunta.txt", "r");
   if(fp == NULL){
      printf("\n\tArchivo no disponible...\n");
      exit(1);
   }
   fscanf(fp, " %[^\n]", handler.question);
   fscanf(fp, " %[^\n]", handler.resp1);
   fscanf(fp, " %[^\n]", handler.resp2);
   fclose(fp);

   fp = fopen("alumnos.txt", "r");
   if(fp == NULL){
      printf("\n\tArchivo no disponible...\n");
      exit(1);
   }
   while(fscanf(fp, " %[^\n]", line) == 1){
      sscanf(line, "%li\t%[^\t]\t%[^\t]\t%i\t%li\t%[^\n]", &temp.studentID, temp.name, temp.address, &temp.zipCode, &temp.phone, temp.mail);
      start = makeQueue(start, temp);
   }
   fclose(fp);

   if(start != NULL){
      handler.ref = start;
      handler.next = handler.ref;
      handler.studentID = handler.next->studentID;
      sprintf(handler.cID, "%ld", start->studentID);
      strcpy(handler.name, handler.next->name);
      strcpy(handler.address, handler.next->address);
      handler.zipCode = handler.next->zipCode;
      sprintf(handler.cZip, "%d", handler.next->zipCode);
      handler.phone = handler.next->phone;
      sprintf(handler.cPhone, "%ld", handler.next->phone);
      strcpy(handler.mail, handler.next->mail);
      handler.start = handler.next->answer;
      handler.stat = handler.start->status;
      sprintf(handler.cStat, "%d", start->answer->status);
   }

   /* 1. Inicializa el ambiente. */
   gtk_init (&argc, &argv);

   /* 2. Se inicializan variables. */
   handler.windowBrowse = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.windowBrowse), "Encuestas Ibero");
   gtk_container_set_border_width(GTK_CONTAINER(handler.windowBrowse), 10);
   gtk_widget_set_size_request(handler.windowBrowse, 500, 600);
   gtk_window_set_position(GTK_WINDOW(handler.windowBrowse), GTK_WIN_POS_CENTER);

   handler.wConsult = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wConsult), "Datos Alumno");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wConsult), 10);
   gtk_widget_set_size_request(handler.wConsult, 400, 400);
   gtk_window_set_position(GTK_WINDOW(handler.wConsult), GTK_WIN_POS_CENTER);

   handler.wZip = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wZip), "Búsqueda CP");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wZip), 10);
   gtk_widget_set_size_request(handler.wZip, 250, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wZip), GTK_WIN_POS_CENTER);

   handler.wSZip = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wSZip), "Búsqueda CP");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wSZip), 10);
   gtk_widget_set_size_request(handler.wSZip, 250, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wSZip), GTK_WIN_POS_CENTER);

   handler.wQuestion = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wQuestion), "Actualizar Pregunta");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wQuestion), 10);
   gtk_widget_set_size_request(handler.wQuestion, 300, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wQuestion), GTK_WIN_POS_CENTER);

   handler.wCall = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wCall), "Marcar alumno");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wCall), 10);
   gtk_widget_set_size_request(handler.wCall, 300, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wCall), GTK_WIN_POS_CENTER);

   handler.wUpdate = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wUpdate), "Actualizar datos");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wUpdate), 10);
   gtk_widget_set_size_request(handler.wUpdate, 300, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wUpdate), GTK_WIN_POS_CENTER);

   handler.wNewS = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wNewS), "Actualizar datos");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wNewS), 10);
   gtk_widget_set_size_request(handler.wNewS, 400, 400);
   gtk_window_set_position(GTK_WINDOW(handler.wNewS), GTK_WIN_POS_CENTER);

   handler.wID = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wID), "Buscar ID");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wID), 10);
   gtk_widget_set_size_request(handler.wID, 250, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wID), GTK_WIN_POS_CENTER);

   handler.wSID = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(handler.wSID), "Buscar ID");
   gtk_container_set_border_width(GTK_CONTAINER(handler.wSID), 10);
   gtk_widget_set_size_request(handler.wSID, 250, 300);
   gtk_window_set_position(GTK_WINDOW(handler.wSID), GTK_WIN_POS_CENTER);

   vbox = gtk_vbox_new(FALSE, 10);
   hboxAns = gtk_hbox_new(FALSE, 2);
   hboxData = gtk_hbox_new(FALSE, 10);
   hboxSearch = gtk_hbox_new(FALSE, 15);
   hboxMove = gtk_hbox_new(FALSE, 15);
   handler.bCall = gtk_button_new_with_label("Llamar alumno actual");
   handler.bID = gtk_button_new_with_label("Buscar ID");
   handler.bZip = gtk_button_new_with_label("Buscar CP");
   handler.bUpdate = gtk_button_new_with_label("Altas y bajas de alumnos");
   handler.bPrev = gtk_button_new_with_label("Prev");
   handler.bConsult = gtk_button_new_with_label("Ver datos completos");
   handler.bQuestion = gtk_button_new_with_label("Actualizar pregunta");
   handler.bNext = gtk_button_new_with_label("Next");
   handler.labelQuestion = gtk_label_new(handler.question);
   handler.labelOpt1 = gtk_label_new("Respuesta 1: ");
   handler.labelResp1 = gtk_label_new(handler.resp1);
   handler.labelOpt2 = gtk_label_new("Respuesta 2: ");
   handler.labelResp2 = gtk_label_new(handler.resp2);
   handler.labelName = gtk_label_new(handler.name);
   handler.labelID = gtk_label_new(handler.cID);
   vbZip = gtk_vbox_new(FALSE, 10);
   handler.lZip = gtk_label_new("Ingrese el CP que busca: ");
   handler.inZip = gtk_entry_new();
   handler.bwZip = gtk_button_new_with_label("Confirmar");
   vbSZip = gtk_vbox_new(FALSE, 10);
   hbSZip = gtk_hbox_new(FALSE, 10);
   handler.bwSZip = gtk_button_new_with_label("Regresar");
   handler.bwNZip = gtk_button_new_with_label("Next");
   handler.bwPZip = gtk_button_new_with_label("Prev");
   handler.lSZip = gtk_label_new("Nadie tiene ese CP");
   vbConsult = gtk_vbox_new(FALSE, 10);
   hbConsult = gtk_hbox_new(FALSE, 10);
   hbConsult1 = gtk_hbox_new(FALSE, 10);
   hbConsult2 = gtk_hbox_new(FALSE, 10);
   hbConsult3 = gtk_hbox_new(FALSE, 10);
   hbConsult4 = gtk_hbox_new(FALSE, 10);
   handler.lCName = gtk_label_new("");
   handler.lCID = gtk_label_new("");
   handler.lCZip = gtk_label_new("");
   handler.lCMail = gtk_label_new("");
   handler.lCPhone = gtk_label_new("");
   handler.lCAddress = gtk_label_new("");
   handler.lCStat = gtk_label_new("");
   lCPhone = gtk_label_new("Teléfono: ");
   lCMail = gtk_label_new("Mail: ");
   lCID = gtk_label_new("Número de Cuenta: ");
   lCStat = gtk_label_new("Estado: ");
   handler.bwConsult = gtk_button_new_with_label("Regresar");
   vbQuestion = gtk_vbox_new(FALSE, 10);
   hbQuest1 = gtk_hbox_new(FALSE, 10);
   hbQuest2 = gtk_hbox_new(FALSE, 10);
   hbQuest3 = gtk_hbox_new(FALSE, 10);
   handler.inQuestion = gtk_entry_new();
   handler.inResp1 = gtk_entry_new();
   handler.inResp2 = gtk_entry_new();
   handler.bwQuestion = gtk_button_new_with_label("Confirmar");
   handler.lQuestion = gtk_label_new("Nueva pregunta: ");
   handler.lResp1 = gtk_label_new("Nueva respuesta 1");
   handler.lResp2 = gtk_label_new("Nueva respuesta 2");
   vbCall = gtk_vbox_new(FALSE, 10);
   hbCall1 = gtk_hbox_new(FALSE, 10);
   hbCall2 = gtk_hbox_new(FALSE, 10);
   handler.lCall = gtk_label_new("Eliga la respuesta: ");
   handler.b1 = gtk_button_new_with_label("1");
   handler.b2 = gtk_button_new_with_label("2");
   handler.b3 = gtk_button_new_with_label("3");
   handler.b4 = gtk_button_new_with_label("4");
   hbUpdate = gtk_hbox_new(FALSE, 10);
   vbUpdate = gtk_vbox_new(FALSE, 10);
   labelChoose = gtk_label_new("Eliga una opción: ");
   bDelete = gtk_button_new_with_label("Borrar");
   bAdd = gtk_button_new_with_label("Agregar");
   vbNewS = gtk_vbox_new(FALSE, 10);
   hbNew1 = gtk_hbox_new(FALSE, 10);
   hbNew2 = gtk_hbox_new(FALSE, 10);
   hbNew3 = gtk_hbox_new(FALSE, 10);
   hbNew4 = gtk_hbox_new(FALSE, 10);
   hbNew5 = gtk_hbox_new(FALSE, 10);
   hbNew6 = gtk_hbox_new(FALSE, 10);
   lCPhone1 = gtk_label_new("Teléfono: ");
   lCMail1 = gtk_label_new("Mail: ");
   lCID1 = gtk_label_new("Número de Cuenta: ");
   lCZip = gtk_label_new("CP: ");
   lCName = gtk_label_new("Nombre: ");
   lCAddress = gtk_label_new("Dirección: ");
   handler.inAddress = gtk_entry_new();
   handler.inName = gtk_entry_new();
   handler.inPhone = gtk_entry_new();
   handler.inID = gtk_entry_new();
   handler.inZip1 = gtk_entry_new();
   handler.inMail = gtk_entry_new();
   handler.bwUpdate = gtk_button_new_with_label("Agregar alumno");
   vbID = gtk_vbox_new(FALSE, 10);
   handler.labID = gtk_label_new("Ingrese el número de cuenta: ");
   handler.inID1 = gtk_entry_new();
   handler.bwID = gtk_button_new_with_label("Confirmar");
   vbSID = gtk_vbox_new(FALSE, 10);
   handler.lSID = gtk_label_new("No existe ese ID");
   handler.bwSID = gtk_button_new_with_label("Confirmar");

   /* 3. Se agrupan los elementos en tablas. */
   gtk_box_pack_start_defaults(GTK_BOX(vbox), handler.labelQuestion);
   gtk_box_pack_start_defaults(GTK_BOX(hboxAns), handler.labelOpt1);
   gtk_box_pack_start_defaults(GTK_BOX(hboxAns), handler.labelResp1);
   gtk_box_pack_start_defaults(GTK_BOX(hboxAns), handler.labelOpt2);
   gtk_box_pack_start_defaults(GTK_BOX(hboxAns), handler.labelResp2);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), hboxAns);
   gtk_box_pack_start_defaults(GTK_BOX(hboxData), handler.labelName);
   gtk_box_pack_start_defaults(GTK_BOX(hboxData), handler.labelID);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), hboxData);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), handler.bCall);
   gtk_box_pack_start_defaults(GTK_BOX(hboxSearch), handler.bZip);
   gtk_box_pack_start_defaults(GTK_BOX(hboxSearch), handler.bID);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), hboxSearch);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), handler.bUpdate);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), handler.bConsult);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), handler.bQuestion);
   gtk_box_pack_start_defaults(GTK_BOX(hboxMove), handler.bPrev);
   gtk_box_pack_start_defaults(GTK_BOX(hboxMove), handler.bNext);
   gtk_box_pack_start_defaults(GTK_BOX(vbox), hboxMove);

   gtk_box_pack_start_defaults(GTK_BOX(vbZip), handler.lZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbZip), handler.inZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbZip), handler.bwZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbSZip), handler.lSZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbSZip), handler.bwSZip);
   gtk_box_pack_start_defaults(GTK_BOX(hbSZip), handler.bwPZip);
   gtk_box_pack_start_defaults(GTK_BOX(hbSZip), handler.bwNZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbSZip), hbSZip);

   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), handler.lCName);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult1), lCID);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult1), handler.lCID);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), hbConsult1);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult2), lCPhone);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult2), handler.lCPhone);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), hbConsult2);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult3), lCMail);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult3), handler.lCMail);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), hbConsult3);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult4), lCStat);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult4), handler.lCStat);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), hbConsult4);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult), handler.lCAddress);
   gtk_box_pack_start_defaults(GTK_BOX(hbConsult), handler.lCZip);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), hbConsult);
   gtk_box_pack_start_defaults(GTK_BOX(vbConsult), handler.bwConsult);

   gtk_box_pack_start_defaults(GTK_BOX(hbQuest1), handler.lQuestion);
   gtk_box_pack_start_defaults(GTK_BOX(hbQuest1), handler.inQuestion);
   gtk_box_pack_start_defaults(GTK_BOX(vbQuestion), hbQuest1);
   gtk_box_pack_start_defaults(GTK_BOX(hbQuest2), handler.lResp1);
   gtk_box_pack_start_defaults(GTK_BOX(hbQuest2), handler.inResp1);
   gtk_box_pack_start_defaults(GTK_BOX(vbQuestion), hbQuest2);
   gtk_box_pack_start_defaults(GTK_BOX(hbQuest3), handler.lResp2);
   gtk_box_pack_start_defaults(GTK_BOX(hbQuest3), handler.inResp2);
   gtk_box_pack_start_defaults(GTK_BOX(vbQuestion), hbQuest3);
   gtk_box_pack_start_defaults(GTK_BOX(vbQuestion), handler.bwQuestion);

   gtk_box_pack_start_defaults(GTK_BOX(vbCall), handler.lCall);
   gtk_box_pack_start_defaults(GTK_BOX(hbCall1), handler.b1);
   gtk_box_pack_start_defaults(GTK_BOX(hbCall1), handler.b2);
   gtk_box_pack_start_defaults(GTK_BOX(vbCall), hbCall1);
   gtk_box_pack_start_defaults(GTK_BOX(hbCall2), handler.b3);
   gtk_box_pack_start_defaults(GTK_BOX(hbCall2), handler.b4);
   gtk_box_pack_start_defaults(GTK_BOX(vbCall), hbCall2);

   gtk_box_pack_start_defaults(GTK_BOX(vbUpdate), labelChoose);
   gtk_box_pack_start_defaults(GTK_BOX(hbUpdate), bDelete);
   gtk_box_pack_start_defaults(GTK_BOX(hbUpdate), bAdd);
   gtk_box_pack_start_defaults(GTK_BOX(vbUpdate), hbUpdate);

   gtk_box_pack_start_defaults(GTK_BOX(hbNew1), lCName);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew1), handler.inName);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew2), lCID1);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew2), handler.inID);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew3), lCPhone1);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew3), handler.inPhone);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew4), lCMail1);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew4), handler.inMail);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew5), lCAddress);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew5), handler.inAddress);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew6), lCZip);
   gtk_box_pack_start_defaults(GTK_BOX(hbNew6), handler.inZip1);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew1);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew2);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew3);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew4);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew5);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), hbNew6);
   gtk_box_pack_start_defaults(GTK_BOX(vbNewS), handler.bwUpdate);

   gtk_box_pack_start_defaults(GTK_BOX(vbID), handler.labID);
   gtk_box_pack_start_defaults(GTK_BOX(vbID), handler.inID1);
   gtk_box_pack_start_defaults(GTK_BOX(vbID), handler.bwID);

   gtk_box_pack_start_defaults(GTK_BOX(vbSID), handler.lSID);
   gtk_box_pack_start_defaults(GTK_BOX(vbSID), handler.bwSID);

   /* 3. Registro de Callbacks. */
   g_signal_connect(GTK_OBJECT(handler.windowBrowse), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wZip), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wSZip), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wConsult), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wQuestion), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wCall), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wUpdate), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wNewS), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wID), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.wSID), "destroy", G_CALLBACK(closeTheApp), NULL);
   g_signal_connect(GTK_OBJECT(handler.bCall), "clicked", G_CALLBACK(clickCall), &handler);
   g_signal_connect(GTK_OBJECT(handler.bZip), "clicked", G_CALLBACK(clickZip), &handler);
   g_signal_connect(GTK_OBJECT(handler.bID), "clicked", G_CALLBACK(clickID), &handler);
   g_signal_connect(GTK_OBJECT(handler.bUpdate), "clicked", G_CALLBACK(clickUpdate), &handler);
   g_signal_connect(GTK_OBJECT(handler.bPrev), "clicked", G_CALLBACK(clickPrev), &handler);
   g_signal_connect(GTK_OBJECT(handler.bConsult), "clicked", G_CALLBACK(clickConsult), &handler);
   g_signal_connect(GTK_OBJECT(handler.bQuestion), "clicked", G_CALLBACK(clickQuestion), &handler);
   g_signal_connect(GTK_OBJECT(handler.bNext), "clicked", G_CALLBACK(clickNext), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwZip), "clicked", G_CALLBACK(searchZip), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwSZip), "clicked", G_CALLBACK(hideZip), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwPZip), "clicked", G_CALLBACK(movePrev), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwPZip), "clicked", G_CALLBACK(moveNext), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwConsult), "clicked", G_CALLBACK(hideConsult), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwQuestion), "clicked", G_CALLBACK(changeQuest), &handler);
   g_signal_connect(GTK_OBJECT(handler.b1), "clicked", G_CALLBACK(clickB1), &handler);
   g_signal_connect(GTK_OBJECT(handler.b2), "clicked", G_CALLBACK(clickB2), &handler);
   g_signal_connect(GTK_OBJECT(handler.b3), "clicked", G_CALLBACK(clickB3), &handler);
   g_signal_connect(GTK_OBJECT(handler.b4), "clicked", G_CALLBACK(clickB4), &handler);
   g_signal_connect(GTK_OBJECT(bDelete), "clicked", G_CALLBACK(clickBDel), &handler);
   g_signal_connect(GTK_OBJECT(bAdd), "clicked", G_CALLBACK(clickBUp), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwUpdate), "clicked", G_CALLBACK(clickCUp), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwID), "clicked", G_CALLBACK(clickNID), &handler);
   g_signal_connect(GTK_OBJECT(handler.bwSID), "clicked", G_CALLBACK(clickSID), &handler);

   /* 4. Se otorgan jerarquias. */
   gtk_container_add(GTK_CONTAINER(handler.windowBrowse), vbox);
   gtk_container_add(GTK_CONTAINER(handler.wZip), vbZip);
   gtk_container_add(GTK_CONTAINER(handler.wSZip), vbSZip);
   gtk_container_add(GTK_CONTAINER(handler.wConsult), vbConsult);
   gtk_container_add(GTK_CONTAINER(handler.wQuestion), vbQuestion);
   gtk_container_add(GTK_CONTAINER(handler.wCall), vbCall);
   gtk_container_add(GTK_CONTAINER(handler.wUpdate), vbUpdate);
   gtk_container_add(GTK_CONTAINER(handler.wNewS), vbNewS);
   gtk_container_add(GTK_CONTAINER(handler.wID), vbID);
   gtk_container_add(GTK_CONTAINER(handler.wSID), vbSID);

   /* 5. Se muestran los widgets. */
   gtk_widget_show_all(handler.windowBrowse);

   /* 6. Se inicializa el loop. */
   gtk_main();

return 0;
}

