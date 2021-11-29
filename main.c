#include <stdio.h>
#include <string.h>

int main(void) {
  char input[250];

  printf("Enter a sample text:\n");

  fgets(input, 250, stdin);

  printf("You entered: %s\n", input);
  
  return 0;
}