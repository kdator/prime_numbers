#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "search_prime_numbers.h"
#include "check_call_parameters.h"
#include "bitset.h"

int main(int argc, char *argv[]) {

  // Проверка параметров вызова программы.
  long* parameters_array = ParametersHandler_checkCallParameters(argc, argv);

  // Создаётся указатель для записи простых чисел, который будет
  // передан в функцию для поиска.
  int* prime_numbers_array = NULL;

  // Переменная для записи количества найденных простых чисел.
  int quantity = 0;                    

  // Начинается замер времени.
  clock_t time;
  time = clock();

  if ((parameters_array[1] - parameters_array[0]) <= 300000 &&
      parameters_array[1] >= 10000000 &&
      parameters_array[0] >= 10000000) {
    search_by_dividers_enumeration(
      parameters_array[0],
      parameters_array[1],
      &prime_numbers_array,
      &quantity);
  } else {
    search_by_sieve_of_eratosthenes(
      parameters_array[0],
      parameters_array[1],
      &prime_numbers_array,
      &quantity);
  }

  // Замер времени заканчивается.
  time = clock() - time;

  printf("\nTime that program does need to do all iteration in seconds: %f\n\n",
        ((float)time) / CLOCKS_PER_SEC);
  printf("Prime numbers quantity - %i.\n\n", quantity);

  printf("Print prime numbers? (Y/N): ");
	char action;
	scanf("%c", &action);
	if (action == 'Y' || action == 'y') {
    if (parameters_array[0] < 0 &&
        parameters_array[1] < 0) {
      exit(0);
    } else {
      // Если запустился поиск по алгоритму "Решето Эратосфена".
      if (get_bit(1, prime_numbers_array) == 1) { 
        for (long i = (parameters_array[0] - 1); i < parameters_array[1]; i++) {
          if (i > 0 && get_bit(i, prime_numbers_array) == 1) {
            printf("%li is a prime number.\n", i + 1);
          }
        }
      } else {  // Если запустился поиск по перебору делителей.
        for (int i = 0; i < quantity; i++) {
          printf("%li is a prime number.\n", prime_numbers_array[i]);
        }
      }
    }
  }

  free(parameters_array);
  free(prime_numbers_array);
  return 0;
}