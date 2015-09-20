/** File: vigenere.c
 *
 *  Vigenere and Autokey Cipher Implementation Functions
 *
 *  LICENSE: MIT - See LICENSE File
 */


#include <ctype.h>
#include <assert.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

#define NUM_ALPHA ((unsigned char) 26)


/** @func int checkAlphaStr( const char *str )
 *
 *  Returns true if str Has at Least 1 Alphabetical Character
 *  Else, Returns False
 */
int checkAlphaStr( const char *str ) {
  /* Don't Accept NULL Pointer */
  if ( str == NULL )
    return 0;

  /* Look for Alphabetical Character */
  for( ; *str != '\0'; ++str ) {
    if ( isalpha(*str) )
      return 1; /* Found, Return True */
  }

  /* None Found, Return False */
  return 0;
}


/** @func char vShift( char pt, char key )
 *  
 *  Performs a Vigenere Shift of PlainText Character pt
 *  By Amount Indicated by Key Character key
 *  Asserts that pt and key are Alphabetical Characters
 */
char vShift( char pt, char key ) {
  /* Convert pt and key to Shift Amounts for Vigenere */
  unsigned char ptShift = (unsigned char)toupper(pt) - 'A';
  unsigned char keyShift = (unsigned char)toupper(key) - 'A';

  /* Make Sure We're Given Only Alphabetical Characters */
  assert( isalpha(pt) );
  assert( isalpha(key) );

  /* Return Vigenere Shifted Character */
  return 'A' + (char)((ptShift+keyShift)%NUM_ALPHA);
}


/** @func char vUnShift( char ct, char key )
 *  
 *  Undoes a Vigenere Shift on Ciphertext Character ct
 *  By Amount Indicated by Key Character key
 *  Asserts that pt and key are Alphabetical Characters
 */
char vUnShift( char ct, char key ) {
  /* Convert pt and key to Shift Amounts for Vigenere */
  unsigned char ctShift = (unsigned char)toupper(ct) - 'A';
  unsigned char keyShift = (unsigned char)toupper(key) - 'A';

  /* Make Sure We're Given Only Alphabetical Characters */
  assert( isalpha(ct) );
  assert( isalpha(key) );

  /* Return Vigenere Shifted Character */
  return 'A' + (char)((NUM_ALPHA + ctShift - keyShift)%NUM_ALPHA);
}


/** @func void enVigenere( const char *pt, const char *key, char *ct )
 *
 *  Encodes Plaintext pt with Key key and Stores Result Ciphertext in ct
 *  Using Vigenere Cipher
 *
 *  WARNING: ct Must Be Able to Accomodate Space for Result
 *    Length of pt + 1 (NULL TERM) Should Be Enough
 */
void enVigenere( const char *pt, const char *key, char *ct ) {
  const char *curr_pt;  /* PTR to Current Plaintext Character */
  const char *curr_key;  /* PTR to Current Key Character */

  /* Make Sure We're Given Non-NULL Pointers */
  assert( pt != NULL );
  assert( key != NULL );
  assert( ct != NULL );

  /* Make Sure Input has at Least Once Letter Each */
  if ( ! checkAlphaStr( pt ) || ! checkAlphaStr( key ) ) {
    *ct = '\0';
    return;
  }

  /* Perform the Encryption, Storing the Results in ct */
  curr_key = key;
  for ( curr_pt = pt; *curr_pt != '\0'; ++curr_pt ) {
    /* Only Encrypt Alphabetical Characters */
    if ( ! isalpha(*curr_pt) )
      continue;
    /* Skip all Non-Alphabetical char of key */
    while( !isalpha(*curr_key) ) {
      if ( *curr_key == '\0' )
        curr_key = key;
      else
        curr_key++;
    }

    /* Record New Ciphertext char */
    *ct = vShift( *curr_pt, *curr_key );
    ++ct;
    ++curr_key;
  }

  /* NULL Terminate ct */
  *ct = '\0';
}


/** @func void deVigenere( const char *ct, const char *key, char *pt )
 *
 *  Decodes Ciphertext ct with Key key and Stores Result Plaintext in pt
 *  Using Vigenere Cipher
 *
 *  WARNING: pt Must Be Able to Accomodate Space for Result
 *    Length of ct + 1 (NULL TERM) Should Be Enough
 */
void deVigenere( const char *ct, const char *key, char *pt ) {
  const char *curr_ct;  /* PTR to Current Plaintext Character */
  const char *curr_key;  /* PTR to Current Key Character */

  /* Make Sure We're Given Non-NULL Pointers */
  assert( ct != NULL );
  assert( key != NULL );
  assert( pt != NULL );

  /* Make Sure Input has at Least Once Letter Each */
  if ( ! checkAlphaStr( ct ) || ! checkAlphaStr( key ) ) {
    *pt = '\0';
    return;
  }

  /* Perform the Decryption, Storing the Results in ct */
  curr_key = key;
  for ( curr_ct = ct; *curr_ct != '\0'; ++curr_ct ) {
    /* Only Encrypt Alphabetical Characters */
    if ( ! isalpha(*curr_ct) )
      continue;
    /* Skip all Non-Alphabetical char of key */
    while( !isalpha(*curr_key) ) {
      if ( *curr_key == '\0' )
        curr_key = key;
      else
        curr_key++;
    }

    /* Record New Plaintext char */
    *pt = vUnShift( *curr_ct, *curr_key );
    ++pt;
    ++curr_key;
  }

  /* NULL Terminate pt */
  *pt = '\0';
}


/** @func void enAutokey( const char *pt, const char *key, char *ct )
 *
 *  Encodes Plaintext pt with Key key and Stores Result Ciphertext in ct
 *  Using Autokey Cipher
 *
 *  WARNING: ct Must Be Able to Accomodate Space for Result
 *    Length of pt + 1 (NULL TERM) Should Be Enough
 */
void enAutokey( const char *pt, const char *key, char *ct ) {
  const char *curr_pt;  /* PTR to Current Plaintext Character */
  const char *curr_key;  /* PTR to Current Key Character */

  /* Make Sure We're Given Non-NULL Pointers */
  assert( pt != NULL );
  assert( key != NULL );
  assert( ct != NULL );

  /* Make Sure Input has at Least Once Letter Each */
  if ( ! checkAlphaStr( pt ) || ! checkAlphaStr( key ) ) {
    *ct = '\0';
    return;
  }

  /* Perform the Encryption, Storing the Results in ct */
  curr_key = key;
  for ( curr_pt = pt; *curr_pt != '\0'; ++curr_pt ) {
    /* Only Encrypt Alphabetical Characters */
    if ( ! isalpha(*curr_pt) )
      continue;
    /* Skip all Non-Alphabetical char of key */
    while( !isalpha(*curr_key) ) {
      if ( *curr_key == '\0' )
        curr_key = pt;
      else
        curr_key++;
    }

    /* Record New Ciphertext char */
    *ct = vShift( *curr_pt, *curr_key );
    ++ct;
    ++curr_key;
  }

  /* NULL Terminate ct */
  *ct = '\0';
}


/** @func void deAutokey( const char *ct, const char *key, char *pt )
 *
 *  Decodes Ciphertext ct with Key key and Stores Result Plaintext in pt
 *  Using Autokey Cipher
 *
 *  WARNING: pt Must Be Able to Accomodate Space for Result
 *    Length of ct + 1 (NULL TERM) Should Be Enough
 */
void deAutokey( const char *ct, const char *key, char *pt ) {
  const char *curr_ct;  /* PTR to Current Ciphertext Character */
  const char *curr_key;  /* PTR to Current Key Character */
  char *curr_pt = pt;

  /* Make Sure We're Given Non-NULL Pointers */
  assert( ct != NULL );
  assert( key != NULL );
  assert( pt != NULL );

  /* Make Sure Input has at Least Once Letter Each */
  if ( ! checkAlphaStr( ct ) || ! checkAlphaStr( key ) ) {
    *pt = '\0';
    return;
  }

  /* Perform the Decrypt, Storing the Results in curr_pt */
  curr_key = key;
  for ( curr_ct = ct; *curr_ct != '\0'; ++curr_ct ) {
    /* Only Decrypt Alphabetical Characters */
    if ( ! isalpha(*curr_ct) )
      continue;
    /* Skip all Non-Alphabetical char of key */
    while( !isalpha(*curr_key) ) {
      if ( *curr_key == '\0' )
        curr_key = pt;
      else
        curr_key++;
    }

    /* Record New Ciphertext char */
    *curr_pt = vUnShift( *curr_ct, *curr_key );
    ++curr_pt;
    ++curr_key;
  }

  /* NULL Terminate ct */
  *curr_pt = '\0';
}



