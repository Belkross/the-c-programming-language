/* #decompose
- itérer dans toutes les lettres
- vérifier si un caractère est un séparateur
- traiter le cas d’un séparateur
- traiter le cas d’un non séparateur
pas une lettre hors d’un mot -> j’ignore. dans un mot, je sors d’un mot, j’imprime un saut de ligne
je rencontre une lettre, je l’écris. si j’étais hors d’un mot, je rentre dans un mot

#exemple
"a b" donne "a\nb"

#corner case
- la chaine commence et finit par un séparateur
- les mots sont composés d’autre chose que des lettres
- string vide
- string avec seulement des séparateur

#notes
- les mots peuvent être composés de caractères autre que des letters minuscule ou majuscule
*/

#include "test.c"
#include <stdio.h>

int checkIfSeparator(char input);
void printOneWordPerLine(char input[]);

#define A 65
#define Z 90
#define a 97
#define z 122

int main(void) {
  expectToBe(checkIfSeparator('a'), FALSE);
  expectToBe(checkIfSeparator(' '), TRUE);
  expectToBe(checkIfSeparator('\t'), TRUE);
  expectToBe(checkIfSeparator('\n'), TRUE);

  printOneWordPerLine("   salut !!!\n les \ncopains   bien  ? ");
  printOneWordPerLine("   ");
  printOneWordPerLine("");
}

void printOneWordPerLine(char input[]) {
  int inWord = FALSE;

  for (int index = 0; input[index] != '\0'; ++index) {
    char character = input[index];
    int isSeparator = checkIfSeparator(character);

    if (isSeparator == TRUE) {
      if (inWord == TRUE) {
        inWord = FALSE;
        printf("\n");
      }
    } else {
      if (inWord == FALSE) {
        inWord = TRUE;
      }
      printf("%c", character);
    }
  }
}

int checkIfSeparator(char input) { return input == ' ' || input == '\n' || input == '\t'; }