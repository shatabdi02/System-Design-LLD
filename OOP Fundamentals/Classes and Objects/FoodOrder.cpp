#include<bits/stdc++.h>
using namespace std;

class FoodOrder{
private:
  string orderId;
  string customerName;
  vector<string> items;
  double totalAmount;
  bool isPlaced;
  
public:
  FoodOrder(const string &orderId,const string& customerName)
    :orderId(orderId), customerName(customerName),totalAmount(0.0),isPlaced(false){}
    
    void addItem(const string& foodname,  double price){
      if(isPlaced){
        cout<< "Cannot modify a placed order"<< endl;
        return;
      }
      
      items.push_back(foodname);
      totalAmount+=price;
    }
    
    bool placeOrder(){
      if(isPlaced || items.empty()){
        return false;
      }
      
      isPlaced=true;
      return true;
    }
    
    int getOrder() const{
      return items.size();
    }
    
    void displayOrder() const{
      string status= isPlaced? "PLACED" : "PENDING";
      cout<< "Order" <<orderId <<"("<< customerName <<" ) - " <<status <<endl;
      
      for(const auto& item: items){
        cout<< "- "<< item <<endl;
      }
      
      cout<< "Total: $"<< fixed<<setprecision(2)<<totalAmount<<endl;
    }
};


int main(){
  FoodOrder order1("ord-1001", "Ram");
  order1.addItem("kachori",105.68 );
  order1.addItem("khichdi",100.19);
  order1.addItem("halwa",88);
  order1.addItem("thali", 200.78);
  order1.placeOrder();
  
  
  FoodOrder order2("ord-1010","Rahul");
  order2.addItem("naan",30.11);
  order2.addItem("paneer lababdar",180.59);
  order2.placeOrder();
  
  order1.displayOrder();
  cout<<endl;
  order2.displayOrder();
  
  return 0;
}
