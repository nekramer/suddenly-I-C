#include <stdio.h>

int main(){

    // output numbers 1 to 100
    // multiples of 3 print Fizz
    // multiples of 5 print Buzz
    // multiples of 3 and 5 print FizzBuzz


  for (int i = 1; i <= 100; i++){
    if (i % 3 == 0 && i % 5 == 0){
      printf("FizzBuzz\n");
    } else {
      if (i % 3 == 0){
        printf("Fizz\n");
      } else if (i % 5 == 0){
        printf("Buzz\n");
      } else {
        printf("%d\n", i);
      }
    }
 
  }

}