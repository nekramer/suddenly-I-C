#include <stdio.h>
#include <stdbool.h>

// Function to check for leap year
bool is_leap_year(int year){
  if (year % 4 != 0){
    return false;
  } else if (year % 100 != 0){
    return true;
  } else if (year % 400 != 0){
    return false;
  } else {
    return true;
  }
}

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add){
  int days_left_in_month;

  while (days_left_to_add > 0){
    // get number of days in month
    days_left_in_month = days_in_month[*mm] - *dd;
    if (*mm == 2 && is_leap_year(*yy)){
        // add extra day in Feb for leap year
        days_left_in_month++;
    }

    if (days_left_to_add > days_left_in_month){
      days_left_to_add = days_left_to_add - days_left_in_month - 1;
      *dd = 1;
      if (*mm == 12){
        // New year
        *mm = 1;
        *yy = *yy + 1;
      } else {
        *mm = *mm + 1;
      }
    } else {
      *dd = *dd + days_left_to_add;
      days_left_to_add = 0;

    }
  }
}

int main() {

  int mm;
  int dd;
  int yy;
  int days_left_to_add;
  printf("Please enter a date between the years 1800 and 10000 in the format mm dd yyyy and provide the number of days to add to this date:");
  scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  printf("\n%d %d %d\n", mm, dd, yy);

  // print the date in a more human-readable format (ie Jan 1, 2020)
  // days of week
  //how many sundays in a year? how many weekends? how many weekdays?
  //calendar that reminds me of tasks

}