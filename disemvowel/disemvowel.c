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

          
  

    
			
