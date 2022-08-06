#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

  int counter1[] = {0, 0, 0, 0};
  int counter2[] = {0, 0, 0, 0};

  char* s1;
  char* s2;

  printf("Enter a string consisting of the letters a through d:");
  /* Using scanset character ([]) and ^\n to take input until new line
  is encountered. %*c indicates that newline character should be discarded.
  */
  scanf("%[^\n]%*c", s1);
  printf("Enter a second string consisting of the letters a through d to see if it's an anagram:");
  scanf("%[^\n]%*c", s2);

  for (int i = 0; i < strlen(s1); i++){
    if (s1[i] == 'a'){
      counter1[0]++;
    } else if (s1[i] == 'b'){
      counter1[1]++;
    } else if (s1[i] == 'c'){
      counter1[2]++;
    } else if (s1[i] == 'd'){
      counter1[3]++;
    } else {
      printf("Unrecognized character in string.\n");
      exit(0);
    }
  }
  
  for (int i = 0; i < strlen(s2); i++){
    if (s2[i] == 'a'){
      counter2[0]++;
    } else if (s2[i] == 'b'){
      counter2[1]++;
    } else if (s2[i] == 'c'){
      counter2[2]++;
    } else if (s2[i] == 'd'){
      counter2[3]++;
    } else {
      printf("Unrecognized character in string.\n");
      exit(0);
    }
  }

  int flag = 0;
  for (int i = 0; i < sizeof(counter1)/sizeof(int); i++){
    if (counter1[i] != counter2[i]){
      flag = 1;
    }

  }
 
  if (flag == 0){
    printf("Anagram!\n");

  } else {
    printf("Not Anagram!\n");
  }


}