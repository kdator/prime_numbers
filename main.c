#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "SearchPrimeNumbers.h"
#include "ParametersHandler.h"
#include "Bitset.h"

int main(int argc, char *argv[]) {
  int* params = ParametersHandler_checkCallParameters(argc, argv);
  if (params == NULL) {
    printf("\nAn error occured while reading the call parameters. Please, check them again.\n");
    return 0;
  }

  int* prime_numbers = NULL;
  int quantity = 0;                    

  clock_t time = clock();
  if ((params[1] - params[0]) <= 300000 &&
      params[1] >= 10000000 && params[0] >= 10000000)
    SearchPrimeNumbers_dividersEnumeration(params[0], params[1], &prime_numbers, &quantity);
  else
    SearchPrimeNumbers_sieveOfEratosthenes(params[0], params[1], &prime_numbers, &quantity);

  // Замер времени заканчивается.
  time = clock() - time;

  printf("\nTime that program does need to do all iteration in seconds: %f\n\n",
        ((float)time) / CLOCKS_PER_SEC);
  printf("Prime numbers quantity - %i.\n\n", quantity);

  printf("Print prime numbers? (Y/N): ");
	char action;
	scanf("%c", &action);
	if (action == 'Y' || action == 'y') {
    if (params[0] < 0 &&
        params[1] < 0) {
      exit(0);
    } else {
      // Если запустился поиск по алгоритму "Решето Эратосфена".
      if (Bitset_getBit(1, prime_numbers) == 1) { 
        for (int i = (params[0] - 1); i < params[1]; i++) {
          if (i > 0 && Bitset_getBit(i, prime_numbers) == 1) {
            printf("%i is a prime number.\n", i + 1);
          }
        }
      } else {  // Если запустился поиск по перебору делителей.
        for (int i = 0; i < quantity; i++) {
          printf("%i is a prime number.\n", prime_numbers[i]);
        }
      }
    }
  }

  free(params);
  free(prime_numbers);
  return 0;
}