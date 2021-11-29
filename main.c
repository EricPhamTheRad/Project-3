#include <stdio.h>
#include <string.h>

void PrintMenu();

int main(void) {
  char input[250];
  //gets and prints input
  printf("Enter a sample text:\n");

  fgets(input, 250, stdin);

  printf("\nYou entered: %s\n", input);
  
  //print menu
  PrintMenu();

  return 0;
}

void PrintMenu(){
  printf("MENU\n");
  printf("c - Number of non-whitespace characters\n");
  printf("w - Number of words\n");
  printf("f - Fix capitalization\n");
  printf("r - Replace all !'s\n");
  printf("s - Shorten spaces\n");
  printf("q - Quit\n");
}