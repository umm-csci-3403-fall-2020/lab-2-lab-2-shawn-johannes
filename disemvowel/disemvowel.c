#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

int detect_vowel(char currentCharacter) {
  switch(currentCharacter) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      return 1;
    default:
      return 0;
  }
}

int find_array_size(char *toClean) {
  int counter = 1; // Leave an extra space for the null terminator
  for (int i = 0; toClean[i] != '\0'; i++) {
    // Only count non-vowels
    if (detect_vowel(toClean[i]) == 0) {
      counter++;
    }
  }
  return counter;
}

char *disemvowel(char *str) {
  char *disemvoweledArray;
  int outputArraySize = find_array_size(str);
  disemvoweledArray = (char*) calloc(outputArraySize, sizeof(char));

  // Remove vowels
  int counter = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    // Only copy non-vowels from original string
     if (detect_vowel(str[i]) == 0) {
       disemvoweledArray[counter] = str[i];
       counter++;
     }
  }

  // Add null terminator in last index postion
  disemvoweledArray[outputArraySize] = '\0';
  return disemvoweledArray;
}