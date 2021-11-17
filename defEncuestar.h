#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct element{
   int status;
   struct element *next;
}nodeLIFO;

typedef struct student{
   long int studentID;
   char name[40];
   char address[80];
   int zipCode;
   long int phone;
   char mail[40];
   struct student *prev;
   struct student *next;
   nodeLIFO *answer;
}node;

typedef struct base{
   GtkWidget *windowBrowse; //contenido principal Browser
   GtkWidget *labelQuestion, *labelOpt1, *labelResp1, *labelOpt2, *labelResp2, *labelName, *labelID; //labels Browser
   GtkWidget *bZip, *bUpdate, *bID, *bCall, *bNext, *bPrev, *bConsult, *bQuestion; //botones Browser
   GtkWidget *wCall, *lCall, *b1, *b2, *b3, *b4;
   GtkWidget *wID, *wSID, *labID, *inID1, *bwID, *lSID, *bwSID;
   GtkWidget *wUpdate, *wNewS, *inName, *inMail, *inZip1, *inID, *inPhone, *inAddress, *bwUpdate;
   GtkWidget *wConsult, *lCName, *lCAddress, *lCMail, *lCPhone, *lCZip, *lCID, *lCStat, *bwConsult;
   GtkWidget *wQuestion, *inQuestion, *lQuestion, *inResp1, *lResp1, *inResp2, *lResp2, *bwQuestion;
   GtkWidget *wZip, *wSZip, *lZip, *inZip, *bwZip, *lSZip, *bwSZip, *bwPZip, *bwNZip;

   /* Elementos del browser. */
   char question[150], resp1[50], resp2[50];
   long int studentID;
   char cID[7];
   char name[40], tName[40];
   char address[80];
   int zipCode;
   char cZip[5];
   long int phone;
   char cPhone[11];
   char mail[40];
   int stat;
   char cStat[2];
   node *ref, *next, *temp;
   nodeLIFO *start;
}elements;
