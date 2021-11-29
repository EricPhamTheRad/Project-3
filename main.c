#include <stdio.h>
#include <string.h>

int main(void) {
  char input[250];

  fgets(input, 250, stdin);

  printf("%s", input);
  
  return 0;
}