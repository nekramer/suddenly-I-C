#include <stdio.h>

int main() {

const int appleQuantity = 23;
float applePrice = 1.49;
double appleReview;
int appleReviewDisplay;
char appleLocation = 'F';

appleReview = 82.5;
appleReviewDisplay = appleReview;

printf("An apple costs: $%.2f, there are %d in inventory found in section: %c and your customers gave it an average review of %d%%!", applePrice, appleQuantity, appleLocation, appleReviewDisplay);

}