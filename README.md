Vigenere IUP
------------

Simple Vigenere and Autokey Cipher Encrypter/Decrypter in C and IUP

This is just for fun!  The Vigenere and Autokey Ciphers Are NOT SECURE!

You take full responsibility if your data gets stolen!


To Build + Run:
---------
- Clone this repository:
    git clone https://github.com/jedi453/Vigenere-IUP
- Change Directory to Vigenere-IUP
    cd Vigenere-IUP
- Download [IUP](http://webserver2.tecgraf.puc-rio.br/iup/) into Vigenere-IUP Folder
- Extract IUP Archive in Vigenere-IUP, leaving folder "iup" in Vigenere-IUP
- [Make IUP](http://webserver2.tecgraf.puc-rio.br/iup/en/building.html)
- Find Library Path for IUP in iup/lib/SOME-NAME, Where "SOME-NAME" Could be Linux3xx or Windowsxx
- Run GNU Make with the full Library Path you just Found: (Replace "SOME-NAME")
    make IUP_LIB=iup/lib/SOME-NAME
- Run: ( Replace "SOME-NAME" )
    make IUP_LIB=iup/lib/SOME-NAME run

To Build Run - TL;DR:
---------------------
- Needs Sources and Shared Libraries of IUP in Subfolder "iup"
- Make + Run with: ( Where HERE-IT-IS is the Directory Where libiup.so Is )
    make IUP_LIB=HERE-IT-IS run


To Encrypt
----------
- Insert Plaintext in the Top Text Box
- Insert Key in the Second Text Box
- Hit "Encrypt (Vigenere)" or "Encrypt (Autokey)"


To Decrypt
----------
- Insert Ciphertext in the Top Box
- Insert Key in the Second Box
- Hit "Decrypt (Vigenere)" or "Decrypt (Autokey)"


License
-------
Released Under the MIT License, see File LICENSE for Full Text


