#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char *disemvowelResult = disemvowel((char*) "");
  ASSERT_STREQ("", disemvowelResult);
  free(disemvowelResult);
}

TEST(Disemvowel, HandleNoVowels) {
  char *disemvowelResult = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", disemvowelResult);
  free(disemvowelResult);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *disemvowelResult = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", disemvowelResult);
  free(disemvowelResult);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *disemvowelResult = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", disemvowelResult);
  free(disemvowelResult);
}

TEST(Disemvowel, HandlePunctuation) {
  char *disemvowelResult = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", disemvowelResult);
  free(disemvowelResult);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char *disemvowelResult = disemvowel(str);
  ASSERT_STREQ("xyz", disemvowelResult);
  
  free(disemvowelResult);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
