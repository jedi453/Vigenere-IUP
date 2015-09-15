/** File: Vigenere-IUP.c
 *
 *  Main:
 *    Creates + Displays UI and Callbacks for Vigenere-IUP
 *
 *  Author: Daniel Iacoviello
 *
 *  License: See LICENSE File
 */



#include <stdlib.h>
#include <iup.h>

/** Declare Functions to Encrypt/Decrypt */
void enVigenere( const char *in, const char *key, char *out );
void deVigenere( const char *in, const char *key, char *out );
void enAutokey( const char *in, const char *key, char *out );
void deAutokey( const char *in, const char *key, char *out );


/** Callback for "Encrypt (Vigenere)" Button */
int enVigenere_cb( Ihandle *self ) {
  IupMessage("ALERT", "TODO");
  return IUP_DEFAULT;
}


/** Callback for "Decrypt (Vigenere)" Button */
int deVigenere_cb( Ihandle *self ) {
  IupMessage("ALERT", "TODO");
  return IUP_DEFAULT;
}


/** Callback for "Encrypt (Autokey)" Button */
int enAutokey_cb( Ihandle *self ) {
  IupMessage("ALERT", "TODO");
  return IUP_DEFAULT;
}


/** Callback for "Decrypt (Autokey)" Button */
int deAutokey_cb( Ihandle *self ) {
  IupMessage("ALERT", "TODO");
  return IUP_DEFAULT;
}



/*  int main(int argc, char **argv)
 *
 *    Creates + Displays UI for Vigenere-IUP
 */
int main( int argc, char **argv ) {
  Ihandle *dlg;
  Ihandle *inText, *outText, *vbox, *vigenereHbox, *autokeyHbox;
  Ihandle *btnEnVigenere, *btnDeVigenere, *btnEnAutokey, *btnDeAutokey;

  /* Start IUP */
  IupOpen( &argc, &argv );

  /* Create Text Fields */
  inText = IupText(NULL);
  outText = IupText(NULL);
  IupSetAttribute(inText, "MULTILINE", "YES");
  IupSetAttribute(inText, "EXPAND", "YES");
  IupSetAttribute(outText, "MULTILINE", "YES");
  IupSetAttribute(outText, "EXPAND", "YES");

  /* Create Buttons */
  btnEnVigenere = IupButton("Encrypt Vigenere", NULL);
  btnDeVigenere = IupButton("Decrypt Vigenere", NULL);
  btnEnAutokey = IupButton("Encrypt Autokey", NULL);
  btnDeAutokey = IupButton("Decrypt Autokey", NULL);
  IupSetCallback(btnEnVigenere, "ACTION", (Icallback)enVigenere_cb);
  IupSetCallback(btnDeVigenere, "ACTION", (Icallback)deVigenere_cb);
  IupSetCallback(btnEnAutokey, "ACTION", (Icallback)enAutokey_cb);
  IupSetCallback(btnDeAutokey, "ACTION", (Icallback)deAutokey_cb);

  /* Create Container Boxes */
  vigenereHbox = IupHbox(
      btnEnVigenere,
      btnDeVigenere,
      NULL );
  autokeyHbox = IupHbox(
      btnEnAutokey,
      btnDeAutokey,
      NULL );
  vbox = IupVbox(
      inText,
      outText,
      vigenereHbox,
      autokeyHbox,
      NULL );
  IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
  
  /* Create Window/Dialog */
  dlg = IupDialog(vbox);
  IupSetAttribute(dlg, "TITLE", "Vigenere IUP");
  IupSetAttribute(dlg, "SIZE", "QUARTERxHALF");

  /* Show Main Dialog/Window */
  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
  IupSetAttribute(dlg, "USERSIZE", NULL);

  /* IUP Main Loop */
  IupMainLoop();

  /* Close IUP */
  IupClose();
  return 0;
}
