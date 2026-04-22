#include <bits/stdc++.h>
using namespace std;

class Car{
private: 
  string brand;
  string model;
  int speed;
  
public:
  Car(const string& brand,const string& model)
    :brand(brand), model(model),speed(0) {}
    
  
  void accelerate(int increment){
    speed+=increment;
  }
  
  void display_status() const{
    cout<<brand <<" is running at "<< speed <<"km/hr"<<endl;
  }
};

int main(){
  Car kia("maruti","kia");
  Car fararri("tata","fararri");
  
  kia.accelerate(20);
  fararri.accelerate(50);
  
  kia.display_status();
  cout<<"---------------------------------------"<<endl;
  fararri.display_status();
  
  return 0;
}
