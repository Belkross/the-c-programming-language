/* write a program that displays an histogram of the frequence of each character

#decompose
1. count the frequence of each character
2. display an histogram

#peculiarity
- lowercase and uppercase letters counted together
- non letters characters ?
- separators ?

#example
"a" => [1, ...26 letters, seperators, other]

#corner case
*/

#include "util.c"
#include <stdio.h>

#define CHARACTER_TYPE_NUMBER 28
#define a 97
#define z 122
#define A 65
#define Z 90

void writeFrequenceOfCharacterHistogram(char string[]);

int main(void) {
  writeFrequenceOfCharacterHistogram(
      "Hey, just wanted to follow un on our calls. As i mentioned, the company is called Longteng "
      "Electronics, They,re not exactly one of the biggest players, but they’ve been running a stable "
      "business for a while now, and that’s always a good sign. Up until now they’ve mostly done "
      "manufacturing subcontracts, to traditionally their design engineering team has been relatively "
      "small. But they’re looking to grow the department because they want to create new products "
      "in-house, for both domestic and international markets.");
}

int isLowercaseLetter(char character) {
  if (character >= a && character <= z)
    return TRUE;
  else
    return FALSE;
}

int isUppercaseLetter(char character) {
  if (character >= A && character <= Z)
    return TRUE;
  else
    return FALSE;
}

void writeFrequenceOfCharacterHistogram(char string[]) {
  printf("Frequence of character histogram\n");

  int frequences[CHARACTER_TYPE_NUMBER];
  for (int index = 0; index < CHARACTER_TYPE_NUMBER; ++index) {
    frequences[index] = 0;
  }

  for (int index = 0; string[index] != ENDOFSTRING; ++index) {
    int character = string[index];

    if (isLowercaseLetter(character)) {
      ++frequences[character - a];
      continue;
    }

    if (isUppercaseLetter(character)) {
      ++frequences[character - A];
      continue;
    }

    if (checkIfSeparator(character)) {
      ++frequences[CHARACTER_TYPE_NUMBER - 2];
      continue;
    }

    ++frequences[CHARACTER_TYPE_NUMBER - 1];
  }

  // write the frequence
  for (int index = 0; index < CHARACTER_TYPE_NUMBER; ++index) {
    printf("%c ", index + A);

    int counter = frequences[index];
    while (counter > 0) {
      printf("-");
      --counter;
    }

    printf(" %d\n", frequences[index]);
  }
}