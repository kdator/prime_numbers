#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ParametersHandler.h"

static int* checkOneParameter(char* param) {
  int* arguments_array = (int*)malloc(2 * sizeof(int));

  for (int i = 0; i < strlen(param); i++) {
    if ((param[i] >= '0' && param[i] <= '9') || param[0] == '-')
      continue;
    else
      return NULL;     
  }

  arguments_array[0] = 1;
  sscanf(param, "%i", &arguments_array[1]);
  return arguments_array;
}

static int* checkTwoParameters(char* first_param, char* second_param) {
  int* arguments_array = (int*)malloc(2 * sizeof(int));

  for (int i = 0; i < strlen(first_param); i++) {
    if ((first_param[i] >= '0' && first_param[i] <= '9') || first_param[0] == '-')
      continue;
    else
      return NULL;     
  }

  for (int i = 0; i < strlen(second_param); i++) {
    if ((second_param[i] >= '0' && second_param[i] <= '9') || second_param[0] == '-')
      continue;
    else
      return NULL;     
  }

  sscanf(first_param, "%i", &arguments_array[0]);
  sscanf(second_param, "%i", &arguments_array[1]);
  return arguments_array;
}

int* ParametersHandler_checkCallParameters(int argc, char* argv[]) {
  int* arguments_array;

  switch (argc) {
    case 2:
      arguments_array = checkOneParameter(argv[1]);
      break;
    case 3:
      arguments_array = checkTwoParameters(argv[1], argv[2]);
      break;
    default: arguments_array = NULL;
  }

  return arguments_array;
} 