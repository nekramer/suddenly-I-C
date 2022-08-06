#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race{
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};

struct RaceCar{
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};

// Print functions section
void printIntro(void){
  printf("Welcome to the digital race!!!!!\n");
}

void printCountDown(void){
  printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\n", race.currentLap);
  printf("First Place Is: %s in the %s race car!\n",
  race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race){
  printf("Let's all congratulate %s in the %s race car for ann amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!\n");
}

// Logic functions section
int calculateTimeToCompleteLap(void){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime = raceCar->totalLapTime + calculateTimeToCompleteLap();

}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){


  if (raceCar1->totalLapTime <= raceCar2->totalLapTime){
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  } else {
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
  }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  struct Race race = {5, 1, "", ""};
  for (int i = 0; i < race.numberOfLaps; i++){
    race.currentLap = i + 1;
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }

  printCongratulation(race);

}

int main() {
	srand(time(0));
  
    struct RaceCar racer1;
    racer1.driverName = "Nicole";
    racer1.raceCarColor = "green";

    struct RaceCar racer2;
    racer2.driverName = "Jared";
    racer2.raceCarColor = "red";

    printIntro();
    printCountDown();
    startRace(&racer1, &racer2);

};