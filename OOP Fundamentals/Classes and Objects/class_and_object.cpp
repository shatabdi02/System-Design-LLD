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
    FoodOrder(const string& orderId,const string& customerName)
    : orderId(orderId), customerName(customerName),
      totalAmount(0.0),isPlaced(false) {}
      
    void addItem(const string& name, double price){
      if(isPlaced){
        cout<< "Cannot modify a placed order."  <<endl;
        return;
      }
      items.push_back(name);
      totalAmount += price;
    }
    
    bool placeOrder(){
      if(isPlaced || items.empty()){
        return false;
      }
      isPlaced = true;
      return true;
    }
    
    int getItemCount() const{
      return items.size();
    }
    
    void displayOrder() const{
      string status = isPlaced ? "Placed" : "Pending";
      cout<< "Order" <<orderId << "(" << customerName
          << ")-" <<status <<endl;
      for( const auto& item: items){
        cout<<" - " <<item << endl;
      }
      cout<< "Total: $"<< fixed<< setprecision(2)
          << totalAmount <<endl;
    }
};

int main(){
  FoodOrder order1("ORD-101","Ram");
  order1.addItem("Pizza",12.99);
  order1.addItem("Garlic Bread",4.99);
  order1.addItem("Coke", 2.49);
  order1.placeOrder();
  
  FoodOrder order2("ORD-102","Bob");
  order2.addItem("Burger", 9.99);
  order2.addItem("Fries",3.39);
  
  order1.displayOrder();
  cout<<endl;
  order2.displayOrder();
  
  return 0;
}
