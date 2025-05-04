CC=gcc
CFLAGS=-Wall -g
OBJ=main.o Budget.o Ui.o

budget_app: $(OBJ)
	$(CC) -o budget_app $(OBJ)

main.o: main.c Budget.h Ui.h
Budget.o: Budget.c Budget.h
Ui.o: Ui.c Ui.h

clean:
	rm -f *.o budget_app
