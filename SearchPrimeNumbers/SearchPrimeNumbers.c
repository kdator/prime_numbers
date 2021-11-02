#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SearchPrimeNumbers.h"
#include "Bitset.h"

void SearchPrimeNumbers_sieveOfEratosthenes(int lower_limit, int upper_limit,
                                            int** answer_array_pointer, int* quantity) {

  *answer_array_pointer = (int*)malloc(sizeof(int) * 
                            ((upper_limit / (sizeof(int) * 8)) + 1));
  for (int i = 0; i < upper_limit; i++) {
    Bitset_setBit(i, *answer_array_pointer);
  }

  /* see https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes for more info. */
  for (register int i = 2; (i * i) <= upper_limit; i++) {
    if (Bitset_getBit((i - 1), *answer_array_pointer) == 1) {
      for (register int j = (i * i); j <= upper_limit; j += i) {
        Bitset_clearBit((j - 1), *answer_array_pointer);
      }
    }
  }

  int counter = 0;
  for (int i = (lower_limit - 1); i < upper_limit; i++)
    if (i > 0 && Bitset_getBit(i, *answer_array_pointer) == 1)
      counter++;
  *quantity = counter;
}


void SearchPrimeNumbers_dividersEnumeration(int lower_limit, int upper_limit,
                                            int** answer_array_ptr, int* quantity) {
  int counter = 0;
  int composite_flag = 0;
  int sqrt_from_divider = 0; // todo: подумать как заменить старый счётчик для записи чисел в массив.

  *answer_array_ptr = (int*)malloc((upper_limit - lower_limit) * sizeof(int));

  for (int i = lower_limit; i <= upper_limit; i++) {
    counter++;
    composite_flag = 0;
    sqrt_from_divider = sqrt(i);
    for (int j = 2; j <= sqrt_from_divider; j++) {
      if (i != 2 && (i % j) == 0) {
        counter--;
        composite_flag = 1;
        break;
      }
    }
    if (composite_flag) {
      continue;
    }
    (*answer_array_ptr)[counter - 1] = i;
  }

  *quantity = counter;
}