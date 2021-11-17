/*
* @file funEncuestar.c
* @brief Esta archivo contiene algunas funciones que usamos en el archivo encuestar.c
* @date 04/12/2020
*
*/

#include "defEncuestar.h"

nodeLIFO *push(int answer, nodeLIFO *pt);
node *deleteNode(node *pt);
node *findNode(node *pt, long int studentID, node *actual);
void makeReport(node *pt);
node *miniList(node *pt);
void addNode(elements *pt, node info);

/*
* @brief Esta función es el evento de bCall.
* @author Ramón Orraca
* @param *bCall		Esta variable es bCall
* @param handler 	Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickCall(GtkWidget *bCall, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wCall);

return;
}

/*
* @brief Esta función es el evento de bZip.
* @author Ramón Orraca
* @param *bZip          Esta variable es bZip
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickZip(GtkWidget *bZip, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wZip);

return;
}

/*
* @brief Esta función es el evento de bID.
* @author Ramón Orraca
* @param *bID           Esta variable es bID
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickID(GtkWidget *bID, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wID);

return;
}

/*
* @brief Esta función es el evento de bUpdate.
* @author Ramón Orraca
* @param *bUpdate       Esta variable es bUpdate
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickUpdate(GtkWidget *bUpdate, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wUpdate);

return;
}

/*
* @brief Esta función es el evento de bDelete.
* @author Ramón Orraca
* @param *bDelete       Esta variable es bDelete
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickBDel(GtkWidget *bDelete, gpointer handler){
   elements *pt = (elements *)handler;

   pt->next = deleteNode(pt->next);

   pt->studentID = pt->next->studentID;
   sprintf(pt->cID, "%ld", pt->next->studentID);
   strcpy(pt->name, pt->next->name);
   strcpy(pt->address, pt->next->address);
   pt->zipCode = pt->next->zipCode;
   sprintf(pt->cZip, "%d", pt->next->zipCode);
   pt->phone = pt->next->phone;
   sprintf(pt->cPhone, "%ld", pt->next->phone);
   strcpy(pt->mail, pt->next->mail);
   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_label_set_text(GTK_LABEL(pt->labelName), pt->name);
   gtk_label_set_text(GTK_LABEL(pt->labelID), pt->cID);

   gtk_widget_hide(pt->wUpdate);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de bAdd.
* @author Ramón Orraca
* @param *bAdd          Esta variable es bAdd
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickBUp(GtkWidget *bAdd, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->wUpdate);
   gtk_widget_show_all(pt->wNewS);

return;
}

/*
* @brief Esta función es el evento de bwUpdate.
* @author Ramón Orraca
* @param *bwUpdate     Esta variable es bwUpdate
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickCUp(GtkWidget *bwUpdate, gpointer handler){
   elements *pt = (elements *)handler;
   node temp;
   char tID[7], tZip[6], tPhone[11];

   strcpy(tID, gtk_entry_get_text(GTK_ENTRY(pt->inID)));
   sscanf(tID, "%li", &temp.studentID);
   strcpy(tPhone, gtk_entry_get_text(GTK_ENTRY(pt->inPhone)));
   sscanf(tPhone, "%li", &temp.phone);
   strcpy(temp.name, gtk_entry_get_text(GTK_ENTRY(pt->inName)));
   strcpy(tZip, gtk_entry_get_text(GTK_ENTRY(pt->inZip1)));
   sscanf(tZip, "%i", &temp.zipCode);
   strcpy(temp.mail, gtk_entry_get_text(GTK_ENTRY(pt->inMail)));
   strcpy(temp.address, gtk_entry_get_text(GTK_ENTRY(pt->inAddress)));

   addNode(pt, temp);

   gtk_widget_hide(pt->wNewS);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de bPrev.
* @author Ramón Orraca
* @param *bPrev         Esta variable es bPrev
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickPrev(GtkWidget *bPrev, gpointer handler){
   elements *pt = (elements *)handler;

   pt->next = pt->next->prev;

   pt->studentID = pt->next->studentID;
   sprintf(pt->cID, "%ld", pt->next->studentID);
   strcpy(pt->name, pt->next->name);
   strcpy(pt->address, pt->next->address);
   pt->zipCode = pt->next->zipCode;
   sprintf(pt->cZip, "%d", pt->next->zipCode);
   pt->phone = pt->next->phone;
   sprintf(pt->cPhone, "%ld", pt->next->phone);
   strcpy(pt->mail, pt->next->mail);
   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_label_set_text(GTK_LABEL(pt->labelName), pt->name);
   gtk_label_set_text(GTK_LABEL(pt->labelID), pt->cID);

return;
}

/*
* @brief Esta función es el evento de bConsult.
* @author Ramón Orraca
* @param *bConsult      Esta variable es bConsult
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickConsult(GtkWidget *bConsult, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_label_set_text(GTK_LABEL(pt->lCName), pt->name);
   gtk_label_set_text(GTK_LABEL(pt->lCID), pt->cID);
   gtk_label_set_text(GTK_LABEL(pt->lCZip), pt->cZip);
   gtk_label_set_text(GTK_LABEL(pt->lCMail), pt->mail);
   gtk_label_set_text(GTK_LABEL(pt->lCPhone), pt->cPhone);
   gtk_label_set_text(GTK_LABEL(pt->lCAddress), pt->address);
   gtk_label_set_text(GTK_LABEL(pt->lCStat), pt->cStat);

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wConsult);

return;
}

/*
* @brief Esta función es el evento de bQuestion.
* @author Ramón Orraca
* @param *bQuestion     Esta variable es bQuestion
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickQuestion(GtkWidget *bQuestion, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->windowBrowse);
   gtk_widget_show_all(pt->wQuestion);

return;
}

/*
* @brief Esta función es el evento de bNext.
* @author Ramón Orraca
* @param *bNext         Esta variable es bNext
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickNext(GtkWidget *bNext, gpointer handler){
   elements *pt = (elements *)handler;

   pt->next = pt->next->next;

   pt->studentID = pt->next->studentID;
   sprintf(pt->cID, "%ld", pt->next->studentID);
   strcpy(pt->name, pt->next->name);
   strcpy(pt->address, pt->next->address);
   pt->zipCode = pt->next->zipCode;
   sprintf(pt->cZip, "%d", pt->next->zipCode);
   pt->phone = pt->next->phone;
   sprintf(pt->cPhone, "%ld", pt->next->phone);
   strcpy(pt->mail, pt->next->mail);
   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_label_set_text(GTK_LABEL(pt->labelName), pt->name);
   gtk_label_set_text(GTK_LABEL(pt->labelID), pt->cID);

return;
}

/*
* @brief Esta función es el evento de bwConsult.
* @author Ramón Orraca
* @param *bwConsult     Esta variable es bwConsult
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void hideConsult(GtkWidget *bwConsult, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->wConsult);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de bwQuestion.
* @author Ramón Orraca
* @param *bwQuestion     Esta variable es bwQuestion
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void changeQuest(GtkWidget *bwQuestion, gpointer handler){
   FILE *fp;
   elements *pt = (elements *)handler;

   strcpy(pt->resp1, gtk_entry_get_text(GTK_ENTRY(pt->inResp1)));
   strcpy(pt->resp2, gtk_entry_get_text(GTK_ENTRY(pt->inResp2)));
   strcpy(pt->question, gtk_entry_get_text(GTK_ENTRY(pt->inQuestion)));

   gtk_label_set_text(GTK_LABEL(pt->labelQuestion), pt->question);
   gtk_label_set_text(GTK_LABEL(pt->labelResp1), pt->resp1);
   gtk_label_set_text(GTK_LABEL(pt->labelResp2), pt->resp2);

   fp = fopen("pregunta.txt", "w");
   if(fp == NULL){
      printf("\n\tArchivo no disponible...\n");
      exit(1);
   }
   fprintf(fp, "%s\n", pt->question);
   fprintf(fp, "%s\n", pt->resp1);
   fprintf(fp, "%s\n", pt->resp2);
   fclose(fp);

   gtk_widget_hide(pt->wQuestion);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de b1.
* @author Miguel Ángel Meza
* @param *b1            Esta variable es b1
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickB1(GtkWidget *b1, gpointer handler){
   elements *pt = (elements *)handler;
   int ans=1;

   pt->next->answer = push(ans, pt->start);

   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_widget_hide(pt->wCall);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de b2.
* @author Miguel Ángel Meza
* @param *b2            Esta variable es b2
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickB2(GtkWidget *b2, gpointer handler){
   elements *pt = (elements *)handler;
   int ans=2;

   pt->next->answer = push(ans, pt->start);

   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_widget_hide(pt->wCall);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de b3.
* @author Miguel Ángel Meza
* @param *b3            Esta variable es b3
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickB3(GtkWidget *b3, gpointer handler){
   elements *pt = (elements *)handler;
   int ans=3;

   pt->next->answer = push(ans, pt->start);

   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_widget_hide(pt->wCall);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de b4.
* @author Miguel Ángel Meza
* @param *b4            Esta variable es b4
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickB4(GtkWidget *b4, gpointer handler){
   elements *pt = (elements *)handler;
   int ans=4;

   pt->next->answer = push(ans, pt->start);

   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_widget_hide(pt->wCall);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de bNext.
* @author Miguel Ángel Meza
* @param *bNext         Esta variable es bNext
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void moveNext(GtkWidget *bNext, gpointer handler){
   elements *pt = (elements *)handler;

   if(pt->temp == NULL) gtk_label_set_text(GTK_LABEL(pt->lSZip), "Nadie tiene ese CP...");
   else{
      pt->temp = pt->temp->next;
      strcpy(pt->tName, pt->temp->name);
      gtk_label_set_text(GTK_LABEL(pt->lSZip), pt->temp->name);
   }

return;
}

/*
* @brief Esta función es el evento de bPrev.
* @author Miguel Ángel Meza
* @param *bPrev            Esta variable es bPrev
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void movePrev(GtkWidget *bPrev, gpointer handler){
   elements *pt = (elements *)handler;

   if(pt->temp == NULL) gtk_label_set_text(GTK_LABEL(pt->lSZip), "Nadie tiene ese CP...");
   else{
      pt->temp = pt->temp->prev;
      strcpy(pt->tName, pt->temp->name);
      gtk_label_set_text(GTK_LABEL(pt->lSZip), pt->temp->name);
   }

return;
}

/*
* @brief Esta función es el evento de bwZip.
* @author Ramón Orraca
* @param *bNext         Esta variable es bwZip
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void searchZip(GtkWidget *bwZip, gpointer handler){
   char temp[6];
   int sZip, cont=0;
   node *aux, *base;
   elements *pt = (elements *)handler;

   base = pt->ref;
   pt->temp = NULL;
   aux = pt->ref;
   strcpy(temp, gtk_entry_get_text(GTK_ENTRY(pt->inZip)));
   sscanf(temp, "%d", &sZip);

//   do{
      if(aux->zipCode == sZip){
//         pt->temp = miniList(aux, cont);
      }
//   aux = aux->next;
//   }while(aux != base);

   gtk_widget_hide(pt->wZip);
   gtk_widget_show_all(pt->wSZip);

return;
}

/*
* @brief Esta función es el evento de bwSZip.
* @author Ramón Orraca
* @param *bNext         Esta variable es bwSZip
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void hideZip(GtkWidget *bwSZip, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->wSZip);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

void clickNID(GtkWidget *bwID, gpointer handler){
   char temp[7];
   long int sID=0;
   elements *pt = (elements *)handler;

   strcpy(temp, gtk_entry_get_text(GTK_ENTRY(pt->inID1)));
   sscanf(temp, "%li", &sID);
   pt->next = findNode(pt->ref, sID, pt->next);

   pt->studentID = pt->next->studentID;
   sprintf(pt->cID, "%ld", pt->next->studentID);
   strcpy(pt->name, pt->next->name);
   strcpy(pt->address, pt->next->address);
   pt->zipCode = pt->next->zipCode;
   sprintf(pt->cZip, "%d", pt->next->zipCode);
   pt->phone = pt->next->phone;
   sprintf(pt->cPhone, "%ld", pt->next->phone);
   strcpy(pt->mail, pt->next->mail);
   pt->start = pt->next->answer;
   pt->stat = pt->start->status;
   sprintf(pt->cStat, "%d", pt->next->answer->status);

   gtk_label_set_text(GTK_LABEL(pt->labelName), pt->name);
   gtk_label_set_text(GTK_LABEL(pt->labelID), pt->cID);

   gtk_widget_hide(pt->wID);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de bwSID.
* @author Miguel Ángel Meza
* @param *bwSID            Esta variable es bwSID
* @param handler        Esta variable es nuestra estructura handler
* @return NULL          Este return es void
*
*/
void clickSID(GtkWidget *bwSID, gpointer handler){
   elements *pt = (elements *)handler;

   gtk_widget_hide(pt->wSID);
   gtk_widget_show_all(pt->windowBrowse);

return;
}

/*
* @brief Esta función es el evento de destroy en cualquier ventana.
* @author Ramón Orraca
* @param *windowBrowse          Esta variable es la ventana windowBrowse
* @param empty                  Esta variable es NULL
* @return NULL                  Este return es void
*
*/
extern void closeTheApp(GtkWidget *windowBrowse, gpointer empty){

   g_print("\nSe cerro la aplicación...\n\n");
   gtk_main_quit();

return;
}

//#ifdef FULL
/*
* @brief Esta función crea el encadenado de nuestra lista doble.
* @author Ramón Orraca
* @param *pt                    Esta variable es el apuntador start
* @param info			Esta variable es la estructura que contiene los datos del alumno presente
* @return *pt                   Este es un apuntador de tipo node
*
*/
node *makeQueue(node *pt, node info){
   node *newN, *aux;

   aux = pt;
   newN = (node *)malloc(sizeof(node));
   if(newN == NULL){
      printf("\n\n\tNo hay espacio de memoria...\n\n");
      exit(1);
   }
   newN->studentID = info.studentID;
   strcpy(newN->name, info.name);
   strcpy(newN->address, info.address);
   newN->zipCode = info.zipCode;
   newN->phone = info.phone;
   strcpy(newN->mail, info.mail);
   newN->answer = push(0, newN->answer);

   if(pt == NULL){
      pt = newN;
      pt->next = pt;
      pt->prev = pt;
   }
   else{
      aux = pt->prev;
      aux->next = newN;
      newN->prev = aux;
      pt->prev = newN;
      newN->next = pt;
   }

return (pt);
}

/*
* @brief Esta función imprime la lista doble.
* @author Ramón Orraca
* @param *pt                    Esta variable es el apuntador inicio
* @return NULL                  Este return es void
*
*/
extern void printQueue(node *pt){
   node *aux;

   system("clear");
   printf("\n\n\tLos alumnos a llamar son los siguientes:\n\n");
   if(pt != NULL){
      aux = pt;
      do{
         printf("   (%i) %li\t%s\t%s\t%i\t%li\t%s\n", aux->answer->status, aux->studentID, aux->name, aux->address, aux->zipCode, aux->phone, aux->mail);
         aux = aux->next;
      }while(aux != pt);
   } else printf("\n\n\tLa lista doble está vacía...\n\n");
   printf("\n\n");

return;
}

/*
* @brief Esta función permite navegar en la lista e ir obteniendo información analítica del contenido de cada nodo. Esta función ofrece un menú de opciones.
* @author Miguel Meza
* @param *pt                    Esta variable es el apuntador start
* @return NULL                  Este return es void
*
*/
extern void browseNode(node *pt, char *question){
#ifdef FULL
   browser browse;
   char option = '0';
   long int search = 0;
   int answer;

   strcpy(browse.question, question);
   if(pt != NULL){
      browse.ref = pt;
      browse.next = pt;
      browse.start = NULL;

      while(option != 's'){
	 answer = 0;
         browse.studentID = browse.next->studentID;
         strcpy(browse.name, browse.next->name);
         strcpy(browse.address, browse.next->address);
         strcpy(browse.zipCode, browse.next->zipCode);
         browse.phone = browse.next->phone;
         strcpy(browse.mail, browse.next->mail);
         browse.start = browse.next->answer;

         printf("\n\tPregunta: %s\n\tAlumno: %s (%li)\n\tRespuesta: %i", browse.question, browse.name, browse.studentID, browse.start->status);
         printf("\n\n\tDame la opción [d]erecha, [i]zquierda, [a]ctualizar estatus, [n]úmero de cuenta, [b]orrar, [r]eportar, [v]er alumnos ó [s]alir: ");
         scanf(" %c", &option);
         if(option == 'd'){
            browse.next = browse.next->next;
         }
         if(option == 'i'){
            browse.next = browse.next->prev;
         }
         if(option == 'a'){
	    while((answer <= 0)||(answer > 4)){
               printf("\n\tIngrese el nuevo status del alumno: ");
	       scanf(" %i", &answer);
	    }
            browse.next->answer = push(answer, browse.start);
	    printf("\n\tLa lista LIFO contiene: \n");
         }
         if(option == 'n'){
            printQueue(pt);
	    printf("\n\tIngrese el número de cuenta: ");
            scanf(" %li", &search);
	    browse.next = findNode(pt, search, browse.next);
         }
         if(option == 'b'){
	    browse.next = deleteNode(browse.next);
         }
         if(option == 'r'){
            printf("\n\tSe imprimirá el reporte...");
	    makeReport(pt);
         }
         if(option == 'v'){
	    printQueue(pt);
         }
      }
      printf("\n\n\t¡Gracias por utilizar el programa!\n\n");
   }
   else printf("\n\tLista vacía...\n\n");
#endif
return;
}

/*
* @brief Esta función regresa la dirección de memoria donde iniciamos, inserta un nodo en la lista LIFO con un número como contenido.
* @author Ramón Orraca
* @param dat                    Esta variable es el nombre que ingreso el usuario
* @param *pt                    Esta variable es el apuntador inicio
* @return *pt                   Este es un apuntador de tipo nodo
*
*/
nodeLIFO *push(int answer, nodeLIFO *pt){
   nodeLIFO *aux;

   aux = (nodeLIFO*)malloc(sizeof(nodeLIFO));
   if(aux == NULL){
      printf("\nNo hay memoria disponible.");
      exit(1);
   }
   aux->status = answer;
   aux->next = pt;
   pt = aux;

return (pt);
}

/*
* @brief Esta función elimina el nodo que contenga el nodo que ingreso el usuario.
* @author grupo Miguel Meza
* @param *pt                    Esta variable es el nodo que queremos borrar
* @return NULL                  Este return es void
*
*/
node *deleteNode(node *pt){
   node *deleteN;
   char option;

   if(pt != NULL){
      deleteN = pt;
      pt = pt->next;
      deleteN->prev->next = pt;
      pt->prev = deleteN->prev;
      free(deleteN);
   }

return (pt);
}

/*
* @brief Esta función busca el número de cuenta indicado en el queue.
* @author Ramón Orraca
* @param *pt                    Esta variable es el inicio de nuestra lista
* @param studentID	 	Esta variable es el número de cuenta que estamos buscando
* @param *actual		Esta variable es el nodo en el que nos encontramos actualmente
* @return NULL                  Este return es void
*
*/
node *findNode(node *pt, long int studentID, node *actual){
   node *aux;

   aux = pt;
   if(aux->studentID == studentID);
   else{
      do{
         aux = aux->next;
      }while((aux->studentID != studentID) && (aux != pt));
   }

   if(aux->studentID != studentID){
      printf("\n\tEl número de cuenta que busco no existe en el queue...\n");
      aux = actual;
   }

return (aux);
}

/*
* @brief Esta función guarda el reporte en el archivo resultados.txt.
* @author Ramón Orraca
* @param *pt                    Esta variable es el apuntador inicio
* @return NULL                  Este return es void
*
*/
void makeReport(node *pt){
   node *aux;
   time_t t;
   FILE *fp;
   float i=0, count1=0, count2=0, count3=0, count4=0, count0=0;

   time(&t);
   fp = fopen("reporte.txt", "w");
   if(fp == NULL){
      printf("\n\tArchivo no disponible...\n");
      exit(1);
   }
   fprintf(fp, "\tEncuesta a %s\n\n", ctime(&t));
   if(pt != NULL){
      aux = pt;
      do{
         fprintf(fp, "   (%i) %li\t%s\t%s\t%i\t%li\t%s\n", aux->answer->status, aux->studentID, aux->name, aux->address, aux->zipCode, aux->phone, aux->mail);
         aux = aux->next;
	 i++;
	 if(aux->answer->status == 1) count1++;
         if(aux->answer->status == 2) count2++;
         if((aux->answer->status == 3) || (aux->answer->status == 0)) count3++;
         if(aux->answer->status == 4) count4++;
      }while(aux != pt);
   } else fprintf(fp, "\n\n\tLa lista doble está vacía...\n\n");
   fprintf(fp, "\n\tAlumnos encuestados\t[%.0f]\n", i);
   fprintf(fp, "\n\tNo contesto\t[%.0f]\t%%%.2f", count3, count3/i*100);
   fprintf(fp, "\n\tSe dejo recado\t[%.0f]\t%%%.2f", count4, count4/i*100);
   fprintf(fp, "\n\tOpción 2\t[%.0f]\t%%%.2f", count2, count2/i*100);
   fprintf(fp, "\n\tOpción 1\t[%.0f]\t%%%.2f", count1, count1/i*100);

return;
}

/*
* @brief Esta función es el evento de crea la lista de búsqueda por CP.
* @author Miguel Ángel Meza
* @param *pt            Esta variable es la posición inicial de la lista
* @return pt            Este return es la dirección de memoria del nuevo nodo
*
*/
node *miniList(node *pt){
   node *newN, *aux;

   aux = pt;
   newN = (node *)malloc(sizeof(node));
      if(newN == NULL){
      printf("\n\n\tNo hay espacio de memoria...\n\n");
      exit(1);
   }
   newN->studentID = aux->studentID;
   strcpy(newN->name, aux->name);
   strcpy(newN->address, aux->address);
   newN->zipCode = aux->zipCode;
   newN->phone = aux->phone;
   strcpy(newN->mail, aux->mail);
   newN->answer = push(0, newN->answer);

   if(pt == NULL){
      pt = newN;
      pt->next = pt;
      pt->prev = pt;
   }
   else{
      aux = pt->prev;
      aux->next = newN;
      newN->prev = aux;
      pt->prev = newN;
      newN->next = pt;
   }

return (pt);
}

void addNode(elements *pt, node info){
   node *newN, *aux, *start;

   start = pt->ref;
   aux = start->prev;
   newN = (node *)malloc(sizeof(node));
   if(newN == NULL){
      printf("\n\n\tNo hay espacio de memoria...\n\n");
      exit(1);
   }
   newN->studentID = info.studentID;
   strcpy(newN->name, info.name);
   strcpy(newN->address, info.address);
   newN->zipCode = info.zipCode;
   newN->phone = info.phone;
   strcpy(newN->mail, info.mail);
   newN->answer = push(0, newN->answer);

   aux->next = newN;
   newN->prev = aux;
   newN->next = start;
   start->prev = newN;

return;
}

