#define TRUE 1
#define FALSE 0
#define ENDOFSTRING '\0'

int checkIfSeparator(char input) { return input == ' ' || input == '\n' || input == '\t'; }