
CC = gcc
CFLAGS = -Iiup/include -std=c89 -Wall -g
LDFLAGS = -liup -L$(IUP_LIB)
TARGETS = Vigenere-IUP
RUN_FILE = Vigenere-IUP


all: $(TARGETS)

Vigenere-IUP: Vigenere-IUP.o vigenere.o
	$(CC) -o Vigenere-IUP Vigenere-IUP.o vigenere.o $(LDFLAGS)

run: $(RUN_FILE)
	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:$(IUP_LIB)" ./$(RUN_FILE)

.PHONY: clean
clean:
	rm -f *.o $(TARGETS)
