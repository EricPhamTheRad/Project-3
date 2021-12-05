#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
//Prototypes
void PrintMenu();
void ExecuteMenu(char choice, char input[250]);
int CharCheck(char choice);
int GetNumOfNonWSCharacters(char input[250]);
int GetNumOfWords(char input[250]);
void FixCapitalization(char input[250]);
void ShortenSpace(char input[250]);
void ReplaceExclamation(char input[250]);

int main(void) {
  //varible
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
      printf("Number of non-whitespace characters: %d", GetNumOfNonWSCharacters(input));
      break;
    case 'w':
      printf("Number of words: %d", GetNumOfWords(input));
      break;
    case 'f':
      FixCapitalization(input);
      printf("Edited text: %s", input);
      break;
    case 'r':
      ReplaceExclamation(input);
      printf("Edited text: %s", input);
      break;
    case 's':
      ShortenSpace(input);
      printf("Edited text: %s", input);
      break;
    case 'q':
      _Exit(0);
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
  int counter = 0;

  for(int i = 0; i < strlen(input) - 1; i++){
    if(input[i] != ' '){
      counter++;
    }
  }
  return counter;
}

int GetNumOfWords(char input[250]){
  char *theRest, *token;
  theRest = input;
  int count = 0;
  while((token = strtok_r(theRest, " ", &theRest))){
    count++;
  }
  return count;
}

void FixCapitalization(char input[250]){
  bool flag = false;
  input[0] = toupper(input[0]);
  for(int i = 0; i < strlen(input) - 1; i++){
    if(input[i] == ('!') || input[i] == '.' || input[i] =='?'){
      flag = true;
    }
    if(flag == true && isalpha(input[i]) != 0){
      input[i] = toupper(input[i]);
      flag = false;
    }
  }
}

void ReplaceExclamation(char input[250]){
  for(int i = 0; i < strlen(input) - 1; i++){
    if(input[i] == '!'){
      input[i] = '.';
    }
  }

}

void ShortenSpace(char input[250]){
  int j = 0;
  char *clone;
  clone = input;
   for(int i = 0; i < strlen(clone); i++){
      if(clone [i] != ' ' || clone[i + 1] != ' '){
         input[j] = clone[i];
         j++;
      }
   }
   input[j] = '\0';

}