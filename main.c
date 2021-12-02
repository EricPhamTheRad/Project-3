#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void PrintMenu();
void ExecuteMenu(char choice, char input[250]);
int CharCheck(char choice);
int GetNumOfNonWSCharacters(char input[250]);

int main(void) {
  char input[250];
  char choice;
  bool valid;
  //gets and prints input
  printf("Enter a sample text:\n");

  fgets(input, 250, stdin);

  printf("\nYou entered: %s\n", input);
  
  //print menu
  PrintMenu();
  
  //get choice
  printf("Choose an option: \n");
  do{
    scanf("%c", &choice);
    valid = CharCheck(choice);
  } while(valid);
  ExecuteMenu(choice, input);
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
    switch(choice){
    case 'c':
      printf("%d", GetNumOfNonWSCharacters(input));
      break;
    case 'w':
      break;
    case 'f':
      break;
    case 'r':
      break;
    case 's':
      break;
    case 'q':
      break;
  }
  
  
  
}

int CharCheck(char choice){
  switch(choice){
    case 'c':
    case 'w':
    case 'f':
    case 'r':
    case 's':
    case 'q':
      return false;
      break;
    default:
      return true;
  }

}

int GetNumOfNonWSCharacters(char input[250]){
  return 9;


}