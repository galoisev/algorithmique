CC=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=testmain

CLS=clear

all: $(EXEC)

testmain: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: matrice.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

run:
	$(CLS)$
	./$(EXEC)


clean:
	rm -f *.o core
	$(CLS)
	@echo Suppressions de tous les fichiers *.o
	@echo
	@echo

proper:
	rm -f $(EXEC)
	@echo Suppression $(EXEC)
	@echo
	@echo