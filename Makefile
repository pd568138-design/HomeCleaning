CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = home_cleaning

OBJ = main.o customer.o cleaning.o billing.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c customer.h cleaning.h billing.h
	$(CC) $(CFLAGS) -c main.c

customer.o: customer.c customer.h
	$(CC) $(CFLAGS) -c customer.c

cleaning.o: cleaning.c cleaning.h customer.h
	$(CC) $(CFLAGS) -c cleaning.c

billing.o: billing.c billing.h customer.h
	$(CC) $(CFLAGS) -c billing.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean