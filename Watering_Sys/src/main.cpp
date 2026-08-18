#include <Arduino.h>
#include <Wire.h>



//moisture sensor
//will make more counters when there are several motors and/or priority system
int water_count = 0;

//tmr for watering
int count = 0;

//relay normally open,so when closed not enough moisture
int relay;


void setup() {
  // put your setup code here, to run once:
  moistureMoneyPlant();
  moistureAlocasia();
  moisturePathos();
}

void loop() {
  // put your main code here, to run repeatedly:
}

int moistureMoneyPlant(){
  //read of soil
  int moistureLevelCMP = analogRead(A0);

  //need to find baseline for the moisture level for each plant, 30 arbitrary number

  if (moistureLevelCMP <= 300){
    water_count++;
    if (water_count == 5){ //this number will be adjusted for plant
      wateringFunction();
      water_count = 0; //reassign
    }
  }
};

int moistureAlocasia(){
  int moistureLevelA = analogRead(A1);
  if (moistureLevelA <= 300){
    water_count++;
    if (water_count == 5){ //this number will be adjusted for plant
     wateringFunction();
     water_count = 0; //reassign
   }
  }
};

int moisturePathos(){
  int moistureLevelP = analogRead(A2);
  if (moistureLevelP <= 300){
    water_count++;
    if (water_count == 5){ //this number will be adjusted for plant
     wateringFunction();
      water_count = 0; //reassign
    }
  }
};


int wateringFunction() {
  
};