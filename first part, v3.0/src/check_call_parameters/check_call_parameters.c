#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "check_call_parameters.h"

int* check_call_parameters(int arguments_counter, char* arguments_value[]) {
  
  // Если количество параметров вызова программы больше или меньшне нужного,
  // выводится сообщение об ошибке для пользователя.
  if (arguments_counter <= 1 || arguments_counter > 2) {
    printf("\nError reading program call parameters. Must be only one "
           "parameter.\n\n");
    exit(0);
  } else if (arguments_counter == 2) {  // Если был передан один параметр.
  
    int parameter = 0;

    // Считываем переданный параметр.
    // Выводится сообщение об ошибке, если передаваемый параметр - 
    // не целое число.
    for (int i = 0; i < strlen(arguments_value[1]); i++) {
      if ((arguments_value[1][i] >= '0' && arguments_value[1][i] <= '9') ||
          arguments_value[1][0] == '-') {
        continue;
      } else {
        printf("\nError reading program call parameters. Call parameter must "
               "be integer.\n\n");
        exit(0);      
      }
    }

    // Записываем в переменную значение с параметра вызова программы.
    sscanf(arguments_value[1], "%i", &parameter);

    int* arguments_array = (int*)malloc(1 * sizeof(long));
    arguments_array[0] = parameter;
    return arguments_array;
  }
}