/**
 * \file Bitset.h
 * \author kolpakov dmitrii.
 * \brief Имплементация работы с битным представлением данных. Аналог std::bitset из С++.
 * \date 2020-10-25
*/

#ifndef BITSET_H_
#define BITSET_H_

/**
 * \brief Установить бит bit_number в значение '1' внутри массиве bit_array.
 * \param[in] bit_number номер бита.
 * \param[in] bit_array указатель на массив битов.
*/
void Bitset_setBit(long bit_number, int* bit_array);

/**
 * \brief Установить бит bit_number в значение '0' внутри массиве bit_array.
 * \param[in] bit_number номер бита.
 * \param[in] bit_array указатель на массив битов.
*/
void Bitset_clearBit(long bit_number, int* bit_array); 

/**
 * \brief Вернуть значение бита bit_number в массиве bit_array.
 * \param[in] bit_number номер бита.
 * \param[in] bit_array указатель на массив битов.
*/
int Bitset_getBit(long bit_number, int* bit_array);

#endif /* BITSET_H_ */