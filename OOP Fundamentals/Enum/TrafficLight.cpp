#include<bits/stdc++.h>
using namespace std;

enum class TrafficLight { RED,YELLOW,GREEN};

int getDuration(TrafficLight light){
  switch(light){
    case TrafficLight::RED: return 30;
    case TrafficLight::YELLOW: return 5;
    case TrafficLight::GREEN: return 25;
    default: return 0;
  }
}

TrafficLight next(TrafficLight light){
  switch (light){
    case TrafficLight::RED: return TrafficLight::GREEN;
    case TrafficLight::GREEN: return TrafficLight:: YELLOW;
    case TrafficLight::YELLOW: return TrafficLight:: RED;
    default: return light;
  }
}

void display(TrafficLight light){
  string name;
  switch(light){
    case TrafficLight::RED: name= "RED"; break;
    case TrafficLight::YELLOW: name = "YELLOW"; break;
    case TrafficLight::GREEN: name= "GREEN"; break;
  }
  cout<< name << "(" << getDuration(light)<<"s)" << endl;
}

int main(){
  TrafficLight light = TrafficLight::RED;
  for(int i=0; i<6; i++){
    display(light);
    light= next(light);
  }
  return 0;
}
