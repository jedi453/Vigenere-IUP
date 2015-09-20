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
#include <string.h>
#include <iup.h>




/** Declare Functions to Encrypt/Decrypt */
void enVigenere( const char *pt, const char *key, char *ct );
void deVigenere( const char *ct, const char *key, char *pt );
void enAutokey( const char *pt, const char *key, char *ct );
void deAutokey( const char *ct, const char *key, char *pt );


/** Calback for "Clear Fields" Button */
int btnClear_cb( Ihandle *btnClear ) {
  /* Get the Text Fields to Clear */
  Ihandle *inTextField = (Ihandle*) IupGetAttribute(btnClear, "INPUT_TEXT");
  Ihandle *keyTextField = (Ihandle*) IupGetAttribute(btnClear, "KEY_TEXT");
  Ihandle *outTextField = (Ihandle*) IupGetAttribute(btnClear, "OUTPUT_TEXT");

  /* Clear the Text Fields */
  IupSetAttribute(inTextField, "VALUE", "");
  IupSetAttribute(keyTextField, "VALUE", "");
  IupSetAttribute(outTextField, "VALUE", "");

  return IUP_DEFAULT;
}

/** Callback for "Encrypt (Vigenere)" Button */
int enVigenere_cb( Ihandle *btnEnVigenere ) {
  Ihandle *inTextField = (Ihandle*) IupGetAttribute(btnEnVigenere, "INPUT_TEXT");
  Ihandle *keyTextField = (Ihandle*) IupGetAttribute(btnEnVigenere, "KEY_TEXT");
  Ihandle *outTextField = (Ihandle*) IupGetAttribute(btnEnVigenere, "OUTPUT_TEXT");
  const char *plainText = IupGetAttribute(inTextField, "VALUE");
  const char *keyText = IupGetAttribute(keyTextField, "VALUE");
  char *outText;
  size_t ptSize = IupGetInt(inTextField, "COUNT");
 
  /* Allocate Temporary Memory For Output */
  outText = (char*) malloc((ptSize+1) * sizeof(char));

  if ( outText != NULL ) {
    /* Encrypt the Given plainText with the Given keyText */
    enVigenere(plainText, keyText, outText);

    /* Copy the Result to the outTextField */
    IupSetStrAttribute(outTextField, "VALUE", outText);

    /* Done With outText */
    free(outText);
  } 

  return IUP_DEFAULT;
}


/** Callback for "Decrypt (Vigenere)" Button */
int deVigenere_cb( Ihandle *btnDeVigenere ) {
  Ihandle *inTextField, *keyTextField, *outTextField;
  const char *cipherText;
  const char *keyText;
  char *plainText;
  size_t inSize; /* The Size of the String in inTextField */
  
  inTextField = (Ihandle*) IupGetAttribute(btnDeVigenere, "INPUT_TEXT");
  keyTextField = (Ihandle*) IupGetAttribute(btnDeVigenere, "KEY_TEXT");
  outTextField = (Ihandle*) IupGetAttribute(btnDeVigenere, "OUTPUT_TEXT");

  cipherText = IupGetAttribute(inTextField, "VALUE");
  keyText = IupGetAttribute(keyTextField, "VALUE");
  inSize = IupGetInt(inTextField, "COUNT");

  /* Allocate Output String */
  plainText = (char*) malloc( (inSize+1) * sizeof(char) );

  if ( plainText != NULL ) {
    /* Decrypt the Given cipherText With Given keyText */
    deVigenere(cipherText, keyText, plainText);

    /* Copy Result to ouTextField */
    IupSetStrAttribute(outTextField, "VALUE", plainText);

    free( plainText );
  }

  return IUP_DEFAULT;
}


/** Callback for "Encrypt (Autokey)" Button */
int enAutokey_cb( Ihandle *btnEnAutokey ) {
  Ihandle *inTextField, *keyTextField, *outTextField;
  const char *plainText;
  const char *keyText;
  char *cipherText;
  size_t inSize; /* The Size of the String in inTextField */

  /* Get Text Field Elements */
  inTextField = (Ihandle*) IupGetAttribute(btnEnAutokey, "INPUT_TEXT");
  keyTextField = (Ihandle*) IupGetAttribute(btnEnAutokey, "KEY_TEXT");
  outTextField = (Ihandle*) IupGetAttribute(btnEnAutokey, "OUTPUT_TEXT");

  /* Get Text Field Contents */
  plainText = IupGetAttribute(inTextField, "VALUE");
  keyText = IupGetAttribute(keyTextField, "VALUE");
  inSize = IupGetInt(inTextField, "COUNT");

  cipherText = (char*) malloc( (inSize+1) * sizeof(char) );

  if ( cipherText != NULL ) {
    /* Encrypt the Given Plaintext With the Given Key */
    enAutokey(plainText, keyText, cipherText);

    /* Set the Result as the Contents to the Output Text Field */
    IupSetStrAttribute(outTextField, "VALUE", cipherText);

    /* Free the Dynamically Allocated Memory */
    free( cipherText );
  }

  return IUP_DEFAULT;
}


/** Callback for "Decrypt (Autokey)" Button */
int deAutokey_cb( Ihandle *btnDeAutokey ) {
  Ihandle *inTextField, *keyTextField, *outTextField;
  const char *cipherText;
  const char *keyText;
  char *plainText;
  size_t inSize; /* The Number of chars in The Input */

  /* Get Text Field Elements */
  inTextField = (Ihandle*) IupGetAttribute(btnDeAutokey, "INPUT_TEXT");
  keyTextField = (Ihandle*) IupGetAttribute(btnDeAutokey, "KEY_TEXT");
  outTextField = (Ihandle*) IupGetAttribute(btnDeAutokey, "OUTPUT_TEXT");

  /* Get Text Field Contents */
  cipherText = IupGetAttribute(inTextField, "VALUE");
  keyText = IupGetAttribute(keyTextField, "VALUE");
  inSize = IupGetInt(inTextField, "COUNT");

  /* Allocate Memory for the Output */
  plainText = (char*) malloc( (inSize+1) * sizeof(char) );

  /* If Memory was Allocated Successfully, Decipher Text and Show Result */
  if ( plainText != NULL ) {
    /* Decrypt */
    deAutokey( cipherText, keyText, plainText );

    /* Fill the Output Field with the Result */
    IupSetStrAttribute( outTextField, "VALUE", plainText );

    /* Free Dynamically Allocated Memory */
    free( plainText );
  }

  return IUP_DEFAULT;
}



/*  int main(int argc, char **argv)
 *
 *    Creates + Displays UI for Vigenere-IUP
 */
int main( int argc, char **argv ) {
  Ihandle *dlg;
  Ihandle *inText, *keyText, *outText, *vbox, *vigenereHbox, *autokeyHbox;
  Ihandle *btnEnVigenere, *btnDeVigenere, *btnEnAutokey, *btnDeAutokey;
  Ihandle *btnClear;

  /* Start IUP */
  IupOpen( &argc, &argv );

  /* Create Text Fields */
  inText = IupText(NULL);
  keyText = IupText(NULL);
  outText = IupText(NULL);
  IupSetAttribute(inText, "MULTILINE", "YES");
  IupSetAttribute(inText, "EXPAND", "YES");
  /* IupSetAttribute(keyText, "EXPAND", "YES"); */
  IupSetAttribute(outText, "MULTILINE", "YES");
  IupSetAttribute(outText, "EXPAND", "YES");

  /* Create Buttons */
  btnEnVigenere = IupButton("Encrypt Vigenere", NULL);
  btnDeVigenere = IupButton("Decrypt Vigenere", NULL);
  btnEnAutokey = IupButton("Encrypt Autokey", NULL);
  btnDeAutokey = IupButton("Decrypt Autokey", NULL);

  btnClear = IupButton("Clear Fields", NULL);

  IupSetCallback(btnEnVigenere, "ACTION", (Icallback)enVigenere_cb);
  IupSetCallback(btnDeVigenere, "ACTION", (Icallback)deVigenere_cb);
  IupSetCallback(btnEnAutokey, "ACTION", (Icallback)enAutokey_cb);
  IupSetCallback(btnDeAutokey, "ACTION", (Icallback)deAutokey_cb);
  IupSetCallback(btnClear, "ACTION", (Icallback)btnClear_cb);

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
      keyText,
      outText,
      vigenereHbox,
      autokeyHbox,
      IupFill(),
      btnClear,
      NULL );
  IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
  
  /* Create Window/Dialog */
  dlg = IupDialog(vbox);
  IupSetAttribute(dlg, "TITLE", "Vigenere IUP");
  IupSetAttribute(dlg, "SIZE", "QUARTERxHALF");
  IupSetAttribute(dlg, "INPUT_TEXT", (char*)inText);
  IupSetAttribute(dlg, "KEY_TEXT", (char*)keyText);
  IupSetAttribute(dlg, "OUTPUT_TEXT", (char*)outText);

  /* Show Main Dialog/Window */
  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
  IupSetAttribute(dlg, "USERSIZE", NULL);

  /* IUP Main Loop */
  IupMainLoop();

  /* Close IUP */
  IupClose();
  return 0;
}
