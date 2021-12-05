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
    //checkst to see if its a valid choice
    valid = CharCheck(choice);
  } while(valid);
  //does choice to input
  ExecuteMenu(choice, input);
  return 0;
}

//prints menu options
void PrintMenu(){
  printf("MENU\n");
  printf("c - Number of non-whitespace characters\n");
  printf("w - Number of words\n");
  printf("f - Fix capitalization\n");
  printf("r - Replace all !'s\n");
  printf("s - Shorten spaces\n");
  printf("q - Quit\n");
}

//check what choice is made and does the choice
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
//if its c, w, f, r, s, or q it returns false, false stops the while loop in main
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
//interates through a string, each time it encounters a non space character it adds to counter
int GetNumOfNonWSCharacters(char input[250]){
  int counter = 0;

  for(int i = 0; i < strlen(input) - 1; i++){
    if(input[i] != ' '){
      counter++;
    }
  }
  return counter;
}

//learn this from this video: https://www.youtube.com/watch?v=cCdn7Cy6TfE
int GetNumOfWords(char input[250]){
  //two new strings theRest and token
  char *theRest, *token;
  //the rest gets the stuff within input
  theRest = input;
  int count = 0;
  /*strtok_r takes input string splits it at ' ', and stores it at token, adds to count. 
  It goes throguht the entier string. I think this is how it works
  */
  while((token = strtok_r(theRest, " ", &theRest))){
    count++;
  }
  return count;
}
/*
Checks to see if its an ending punction mark.
If so the next characters will be capitalized.
Once it capitalizes it no longer capilize letter until flag is activated.
*/
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
//iterates through string, if its an ! changes into .
void ReplaceExclamation(char input[250]){
  for(int i = 0; i < strlen(input) - 1; i++){
    if(input[i] == '!'){
      input[i] = '.';
    }
  }

}
//makes new string local
//puts input into clone
//iterates through string, if the current location is not a space or the next spot is also not a spaces it puts it into input
// like ".  P", first postion . is not a spaces so it gets transfered
// the second position it's a space and so is the next so it doesn't throught
// the third postion is a space and but the ones next to it isn't so it goes through
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
   //adds terminator so it doens't break
   input[j] = '\0';

}