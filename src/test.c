#include <stdio.h>

// global
#define TRUE 1
#define FALSE 0
#define ENDOFSTRING '\0'

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RED "\x1b[31m"
int testId = 0;

short expectToBe(int result, int expectation) {
  ++testId;
  char testOK;

  testOK = result == expectation;
  testOK ? printf(ANSI_COLOR_GREEN "OK " ANSI_COLOR_RESET) : printf(ANSI_COLOR_RED "FAIL " ANSI_COLOR_RESET);
  printf("case: %d, result: %d, expectation: %d\n", testId, result, expectation);

  if (testOK)
    return TRUE;
  else
    return FALSE;
}
