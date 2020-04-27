#include "bitset.h"

// Возвращает целочисленное значение для индексации в битовом массиве.
int bit_index(long bit_number) { 
  
  return bit_number / (sizeof(int) * 8); 
  
}

// Возвращает целочисленное значение позиции бита в каком-то байте.
int bit_offset(long bit_number) { 
  
  return bit_number % (sizeof(int) * 8);
  
}

// Устанавливает конкретный бит в позицию 1.
void set_bit(long bit_number, int* bit_array) { 

  bit_array[bit_index(bit_number)] |= 0x01 << (bit_offset(bit_number));

}

// Устанавливает конкретный бит в позиции 0.
void clear_bit(long bit_number, int* bit_array) { 

  bit_array[bit_index(bit_number)] &= ~(0x01 << (bit_offset(bit_number)));

}

// Возвращает значение бита из определённой позиции.
int get_bit(long bit_number, int* bit_array) { 

  return (bit_array[bit_index(bit_number)] >> bit_offset(bit_number) & 1);

}