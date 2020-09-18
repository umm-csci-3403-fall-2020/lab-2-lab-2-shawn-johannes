#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);
  
  printf("Enter a phrase to disemvowel. Enter q to quit \n");

  while (getline(&line, &size, stdin) > 0 && line[0] != 'q') {
    char *disemvowelResult = disemvowel(line);
    printf("%s\n", disemvowelResult);
    free(disemvowelResult);
  }

  
  free(line);
}
