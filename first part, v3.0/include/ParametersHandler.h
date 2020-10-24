/**
 * \file ParametersHandler.h
 * \author kolpakov dmitrii
 * \date 2020-10-24
 * \brief Проверка входящих параметров с консоли.
 */
#ifndef PARAMETERS_HANDLER_H_
#define PARAMETERS_HANDLER_H_

/**
 * \brief Проверяет количество параметров и сравнивает их между друг другом.
 * \param argc количество входящих аргументов.
 * \param argv аргументы в виде С-strings.
 * \return Если считывание успешное - указатель на целочисленный массив параметров. 
 *         Наименьший параметр помещается в 0 позицию массива, наибольший - в 1.
 *         Если неудачное - NULL.
 */
int* ParametersHandler_checkCallParameters(int argc, char* argv[]);

#endif /* PARAMETERS_HANDLER_H_ */