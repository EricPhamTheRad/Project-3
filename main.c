#include <stdio.h>
#include <string.h>

void PrintMenu();
void ExecuteMenu(char choice, char input[250]);

int main(void) {
  char input[250];
  char choice;
  //gets and prints input
  printf("Enter a sample text:\n");

  fgets(input, 250, stdin);

  printf("\nYou entered: %s\n", input);
  
  //print menu
  PrintMenu();
  
  //get choice
  printf("Choose an option: \n");
  choices: 
  scanf("%c", &choice);
  switch(choice){
    case 'c':
      printf("%c", choice);
      break;
    case 'w':
      printf("%c", choice);
      break;
    case 'f':
      printf("%c", choice);
      break;
    case 'r':
      printf("%c", choice);
      break;
    case 's':
      printf("%c", choice);
      break;
    case 'q':
      printf("%c", choice);
      break;
    default:
      goto choices;
  }
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

void ExecuteMenu(char choice, char input[250]){
    
  
  
  
}