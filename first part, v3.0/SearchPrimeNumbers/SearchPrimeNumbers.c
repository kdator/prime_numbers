#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "SearchPrimeNumbers.h"
#include "bitset.h"

void search_by_sieve_of_eratosthenes(long lower_limit,
                                     long upper_limit,
                                     int** answer_array_pointer,
                                     int* quantity) {

  // Выделяется память под переданный указатель для массива чисел.
  // Далее массив заполняется логической единицей.
  *answer_array_pointer = (int*)malloc(sizeof(long) * 
                            ((upper_limit / (sizeof(long) * 8)) + 1));
  for (long i = 0; i < upper_limit; i++) {
    set_bit(i, *answer_array_pointer);
  }

  // Проверяем числа по алгоритму до того момента, пока (i ^ 2) <= upper_limit,
  // так как на каждой итерации будут "вычёркиваться" составные числа и поэтому
  // нам не придётся проверять абсолютна все числа в первом цикле.
  // "Вычёркивание" чисел начинается с (i * i) позиции, так как каждое число 
  // <i> будет являться простым числом, а все остальные числа, расположенные 
  // на расстоянии в <i>, являются составными.
  for (register long i = 2; (i * i) <= upper_limit; i++) {
    if (get_bit((i - 1), *answer_array_pointer) == 1) {
      for (register long j = (i * i); j <= upper_limit; j += i) {
        clear_bit((j - 1), *answer_array_pointer);
      }
    }
  }

  // Объявление счётчика для подсчёта количества простых чисел в массиве.
  int counter = 0;
  for (long i = (lower_limit - 1); i < upper_limit; i++) {
    if (i > 0 && get_bit(i, *answer_array_pointer) == 1) {  
      counter++;
    }
  }

  // Присваиваем переданной переменной "quantity" количество найденных
  // простых чисел.
  *quantity = counter;
}


void search_by_dividers_enumeration(long lower_limit,
                                    long upper_limit, 
                                    int** answer_array,
                                    int* quantity) {

  // Объявление счётчика для подсчёта количества простых чисел в массиве.
  int counter = 0;

  // Выделяем память под массив чисел в величину, равной разности первой и
  // послденей позиции в диапазоне.
  *answer_array = (int*)malloc((upper_limit - lower_limit) * sizeof(int));

  // Первый цикл перебирает все числа в диапазоне от первой до последней
  // позиции в диапазоне.
  //
  // Второй цикл перебирает все числа до половины последнего числа в диапазоне
  // для поиска целочисленных делителей для числа из первого цикла.
  //
  // Счетчик увеличивается на каждое число из диапазона, считаясь простым  
  // числом, но если второй цикл обнаруживает, что число из первого цикла -
  // составное, то он возвращает счётчик к предыдущему значению. 
  // Таким образом, мы проходим все числа в диапазоне и сохраняем только
  // простые числа.
  // Переменная <composite_flag> отвечает за запись простых чисел в массив. 
  // Если число во втором цикле является составным, флагу присваивается 
  // значение 1 и при дальнейшей проверке цикл переходит на новую итерацию. 
  // В противном случае наше число является простым и записывается в массив.
  // Переменная <sqrt_from_divider> нужна для получения корня из делителя
  // для того, чтобы в первом цикле в неё записывать результат поиска корня
  // квадратного из каждого делителя, передавая уже переменную во второй 
  // цикл для проверки числа на простоту.
  int composite_flag = 0;
  int sqrt_from_divider = 0;
  for (register long i = lower_limit; i <= upper_limit; i++) {
    counter++;
    composite_flag = 0;
    sqrt_from_divider = sqrt(i);
    for (register long j = 2; j <= sqrt_from_divider; j++) {
      if (i != 2 && (i % j) == 0) {
        counter--;
        composite_flag = 1;
        break;
      }
    }
    if (composite_flag) {
      continue;
    }
    (*answer_array)[counter - 1] = i;
  }

  // Присваиваем переданной переменной "quantity" количество найденных
  // простых чисел.
  *quantity = counter;
}