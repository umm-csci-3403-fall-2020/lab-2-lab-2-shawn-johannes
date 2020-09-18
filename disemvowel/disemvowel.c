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
    if (detect_vowel(toClean[i]) == 0) {
      counter++;
    }
  }
  return counter;
}