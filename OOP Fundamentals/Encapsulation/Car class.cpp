#include<bits/stdc++.h>
using namespace std;

class Car{
  private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
  
  public:
    Car(string b, string m){
      this->brand=b;
      this->model=m;
      isEngineOn=false;
      currentSpeed=0;
    }
    
    int getCurrentSpeed(){
      return this->currentSpeed;
    }
    
    void startEngine(){
      isEngineOn=true;
      cout<< brand<<" "<< model<< ": Engine starts with a roar! "<< endl;
    }
    
    void shiftGear(int gear){
      if(!isEngineOn){
        cout<< brand<<" "<<model<<" : Engine is off ! cannot shift gear. "<< endl;
      }
      currentGear = gear;
      cout<<brand<<" "<<model<<" :Shifted to gear "<< currentGear<<endl;
    }
    
    void accelerate(){
      if(!isEngineOn){
        cout<<brand<<" "<<model<<" :Engine is off! Cannot accelerate. "<<endl;
        return;
      }
      currentSpeed+=20;
      cout<<brand<<" "<<model<<" :Acclerating to "<< currentSpeed<<"km/hr"<<endl;
    }
    
    void brake(){
      currentSpeed -= 20;
      if(currentSpeed < 0) currentSpeed=0;
      cout<<brand<<" "<<model<<" : Braking ! speed is now "<<currentSpeed<<"km/hr"<<endl;
    }
    
    void stopEngine(){
      isEngineOn = false;
      currentSpeed=0;
      currentGear=0;
      cout<<brand<<" "<<model<<" :Engine turned off. "<<endl;
    }
    
    ~Car() {}
};

int main(){
  Car* sportsCar = new Car("Ford", "mustang");
  
  sportsCar->startEngine();
  sportsCar->shiftGear(1);
  sportsCar->accelerate();
  sportsCar->shiftGear(2);
  sportsCar->brake();
  sportsCar->stopEngine();
  
  cout<<"current speed of my sports car is set to "<< sportsCar->getCurrentSpeed()<<endl;
  
  delete sportsCar;
  
  return 0;
}
