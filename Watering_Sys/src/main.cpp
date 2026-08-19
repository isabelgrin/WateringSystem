#include <Arduino.h>
#include <Wire.h>



//moisture sensor
//will make more counters when there are several motors and/or priority system
int water_count_Money = 0;
int water_count_Pathos = 0;
int water_count_Alocasia = 0;

char a = 'a';
char p = 'p';
char c = 'c';

//tmr for checking 
int countA = 0;
int countC = 0;
int countP = 0;

//relay normally open,so when closed not enough moisture
int relay;


void setup() {
  // put your setup code here, to run once:
  moistureMoneyPlant('c');
  moistureAlocasia('a');
  moisturePathos('p');
}

void loop() {
  // put your main code here, to run repeatedly:


}

int moistureMoneyPlant(char c){
  //read of soil
  int moistureLevelCMP = analogRead(A0);

  //need to find baseline for the moisture level for each plant, 30 arbitrary number

  if (moistureLevelCMP <= 300){
    water_count_Money++;
    if (water_count_Money == 5){ //this number will be adjusted for plant
      wateringFunction(c);
      water_count_Money = 0; //reassign
    }
  }
};

int moistureAlocasia(char a){
  int moistureLevelA = analogRead(A1);
  if (moistureLevelA <= 300){
    water_count_Alocasia++;
    if (water_count_Alocasia == 5){ //this number will be adjusted for plant
     wateringFunction(a);
     water_count_Alocasia = 0; //reassign
   }
  }
};

int moisturePathos(char p){
  int moistureLevelP = analogRead(A2);
  if (moistureLevelP <= 300){
    water_count_Pathos++;
    if (water_count_Pathos == 5){ //this number will be adjusted for plant
     wateringFunction(p);
      water_count_Pathos = 0; //reassign
    }
  }
};


int wateringFunction( char t) {
  if (t == 'a'){
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    delay(10000);           //wait 10 seconds before returning back to 
    countA++;
  }
  else if (t == 'c'){
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    delay(10000);           //wait 10 seconds before returning back to 
    countC++;
  }
  else {
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    delay(10000);           //wait 10 seconds before returning back to 
    countP++;
  }
  
  
  
};