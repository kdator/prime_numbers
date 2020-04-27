# Use GCC compiler for building.
CC=gcc
# The level variable contains flags that are passed to the compiler.
CFLAGS=-c -w -g

test: assembly

assembly: main.o search_prime_numbers.o check_call_parameters.o bitset.o
	$(CC) main.o search_prime_numbers.o check_call_parameters.o bitset.o -o test -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

search_prime_numbers.o: search_prime_numbers.c
	$(CC) $(CFLAGS) search_prime_numbers.c

check_call_parameters.o: check_call_parameters.c
	$(CC) $(CFLAGS) check_call_parameters.c

bitset.o: bitset.c
	$(CC) $(CFLAGS) bitset.c

clean:
	rm -rf *.o test