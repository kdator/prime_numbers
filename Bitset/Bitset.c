#include "Bitset.h"

/**
 * \brief Получить индекс элемента массива, в котором находится bit_number.
*/
int Bitset_index(long bit_number) {
  return bit_number / (sizeof(int) * 8);
}

/**
 * \brief Получить номер бита bit_number в байте.
*/
int Bitset_offset(long bit_number) {
  return bit_number % (sizeof(int) * 8);
}

void Bitset_setBit(long bit_number, int* bit_array) {
  bit_array[Bitset_index(bit_number)] |= 0x01 << (Bitset_offset(bit_number));
}

void Bitset_clearBit(long bit_number, int* bit_array) { 
  bit_array[Bitset_index(bit_number)] &= ~(0x01 << (Bitset_offset(bit_number)));
}

int Bitset_getBit(long bit_number, int* bit_array) { 
  return (bit_array[Bitset_index(bit_number)] >> Bitset_offset(bit_number) & 1);
}