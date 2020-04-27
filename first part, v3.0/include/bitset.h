#pragma once

/*

    Данный заголовочный файл реализует работу, непосредственно, с битами.

*/


/*

    Данная функция позволяет по номеру бита <bit_number> узнать в каком индексе
    битового массива мы находимся. Позволяет легко оперировать доступом в 
    область памяти, где содержится нужная нам последовательность битов.

    Возврашщает целочисленное значение, которое предназначено для индексации.

*/
int bit_index(long bit_number);

/*

    Данная функция позволяет по номеру бита <bit_number> узнать его номер
    в байте. Для этого функция делит по модулю номер бита на битовую 
    размерность типа переменной.

    Возвращает целочисленное значение, которое означает номер бита в 
    последовательности внутри одной переменной.

*/
int bit_offset(long bit_number);


/*

    Устанавливает номер бита <bit_number> в битовом массиве <bit_array>
    в логическую единицу.

*/
void set_bit(long bit_number, int* bit_array);

/*

    Устанавливает номер бита <bit_number> в битовом массиве <bit_array> 
    в логический ноль.

*/
void clear_bit(long bit_number, int* bit_array); 

/*

    Возвращает значение конткретного бита <bit_number> в битовом
    массиве <bit_array>.

*/
int get_bit(long bit_number, int* bit_array);