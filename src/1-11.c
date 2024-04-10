#include "test.c"
#include <stdio.h>

#define INWORD TRUE
#define NOTINWORD FALSE
int countWords(char string[]);

int main(void) {
  expectToBe(countWords(""), 0);
  expectToBe(countWords("\t \n"), 0);
  expectToBe(countWords(" deux  mots "), 2);
  expectToBe(countWords("	deux		mots	"), 2);
  expectToBe(countWords("\ndeux\n\nmots\n"), 2);
  expectToBe(countWords("coucou les potes"), 3);
}

int countWords(char string[]) {
  int wordCounter = 0;
  int characterCounter = 0;
  int newlineCounter = 0;
  int state = NOTINWORD;

  printf("case: \n%s\n", string);

  for (int index = 0; string[index] != ENDOFSTRING; ++index) {
    short character = string[index];
    short isALetter = character != ' ' && character != '\t' && character != '\n';
    short isNewline = character == '\n';

    ++characterCounter;

    if (isALetter == TRUE && state == NOTINWORD) {
      state = INWORD;
      ++wordCounter;
    } else if (isALetter == FALSE && state == INWORD) {
      state = NOTINWORD;
    }

    if (isNewline)
      ++newlineCounter;
  }

  printf("line: %d, word: %d, character: %d\n", newlineCounter, wordCounter, characterCounter);
  return wordCounter;
}
