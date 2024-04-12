/* Goal: display an histogram of words length you encounter in a string

#decompose
- iterate in a string until its end
- find words
- count words length
- increment the category of length corresponding
- writting the histogram

#peculiarity
word definition: a suite of everything except separators

#example
"a ab ab" => [1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0]
the last slot is for words with +10 characters

#corner cases
- empty string
- string with only separator
- words not only containing letters
- words with more than 10 character
- when the string don’t finish with a separator
*/

#include "test.c"
#include <stdio.h>
void getWordsLenthArray(char string[]);
int checkIfSeparator(char input);

#define ARRAY_LENGTH 10

int main(void) {
  getWordsLenthArray("* a ab ab aaaa aaaa aaaa more_than_ten_character");
  getWordsLenthArray("");
  getWordsLenthArray("  \n");
  getWordsLenthArray("Hey, just wanted to follow un on our calls. As i mentioned, the company is called Longteng "
                     "Electronics, They,re not exactly one of the biggest players, but they’ve been running a stable "
                     "business for a while now, and that’s always a good sign. Up until now they’ve mostly done "
                     "manufacturing subcontracts, to traditionally their design engineering team has been relatively "
                     "small. But they’re looking to grow the department because they want to create new products "
                     "in-house, for both domestic and international markets.");
}

void getWordsLenthArray(char string[]) {
  int output[ARRAY_LENGTH];
  int inWord = FALSE;

  for (int index = 0; index < ARRAY_LENGTH; ++index) {
    output[index] = 0;
  }

  int counter = 0;
  for (int index = 0; string[index] != ENDOFSTRING; ++index) {
    int character = string[index];
    int isLetter = !checkIfSeparator(character);

    if (isLetter == TRUE) {
      if (inWord == FALSE) {
        inWord = TRUE;
      }
      ++counter;

    } else if (isLetter == FALSE) {
      if (inWord == TRUE) {
        if (counter <= ARRAY_LENGTH - 1) {
          ++output[counter - 1];
        } else {
          ++output[ARRAY_LENGTH - 1];
        }
        inWord = FALSE;
        counter = 0;
      }
    }
  }

  // handling the case when the string don’t ends with a separator. We need to count the last word
  if (inWord == TRUE) {
    if (counter <= ARRAY_LENGTH - 1) {
      ++output[counter - 1];
    } else {
      ++output[ARRAY_LENGTH - 1];
    }
  }

  printf("Horizontal histogram\n");
  for (int index = 0; index < ARRAY_LENGTH; ++index) {
    printf("%2d", index + 1);
    int amount = output[index];
    while (amount > 0) {
      --amount;
      printf("-");
    }

    printf("\n");
  }

  printf("\nVertical histogram\n");
  int highestAmount = 0;
  for (int index = 0; index < ARRAY_LENGTH; ++index) {
    if (output[index] > highestAmount) {
      highestAmount = output[index];
    }
    printf("%d ", index + 1);
  }
  printf("\n");

  for (int index = 1; index <= highestAmount; ++index) {
    for (int index2 = 0; index2 < ARRAY_LENGTH; ++index2) {
      if (output[index2] >= index) {
        printf("| ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return;
}

int checkIfSeparator(char input) { return input == ' ' || input == '\n' || input == '\t'; }