#include<bits/stdc++.h>
using namespace std;

enum class OrderStatus{
  PLACED, CONFIRMED, SHIPPED, DELIVERED, CANCELLED
};

string orderStatusToString(OrderStatus s){
  switch(s){
    case OrderStatus::PLACED:     return "PLACED";
    case OrderStatus::CONFIRMED:  return "CONFIRMED";
    case OrderStatus::SHIPPED:    return "SHIPPED";
    case OrderStatus::DELIVERED:  return "DELIVERED";
    case OrderStatus::CANCELLED:  return "CANCELLED";
    default:                      return "UNKNOWN";
  }
}

struct PaymentMethod{
  string displayName;
  double feePercent;
  
  static const PaymentMethod CREDIT_CARD;
  static const PaymentMethod DEBIT_CARD;
  static const PaymentMethod UPI;
  static const PaymentMethod NET_BANKING;
};

const PaymentMethod PaymentMethod::CREDIT_CARD{"CREDIT CARD",2.5};
const PaymentMethod PaymentMethod::DEBIT_CARD{"DEBIT CARD" ,1.0};
const PaymentMethod PaymentMethod::UPI{"UPI",0.0};
const PaymentMethod PaymentMethod::NET_BANKING{"Net Banking",1.5};

class Order{
private:
    string orderId;
    OrderStatus status;
    PaymentMethod paymentMethod;
    double amount;
    
public:
    Order(const string& orderId,const PaymentMethod& paymentMethod,double amount)
      :orderId(orderId), status(OrderStatus::PLACED),paymentMethod(paymentMethod),
        amount(amount)  {}
        
    bool advanceStatus(){
      switch(status){
        case OrderStatus::PLACED:
          status = OrderStatus::CONFIRMED;
          return true;
        case OrderStatus::CONFIRMED:
          status = OrderStatus::SHIPPED;
          return true;
        case OrderStatus::SHIPPED:
          status = OrderStatus::DELIVERED;
          return true;
        default:
          return false;
      }
    }
    
    bool cancel(){
      if(status == OrderStatus::PLACED || status == OrderStatus::CONFIRMED){
        status = OrderStatus::CANCELLED;
        return true;
      }
      return false;
    }
    
    double getTotalWithFees() const{
      return amount + (amount * paymentMethod.feePercent / 100);
    }
    
    void displayInfo() const{
      printf("Order %s | Status: %s | Payment: %s | Amount: $%.2f (with fees: $%.2f)\n" ,
      orderId.c_str(),
      orderStatusToString(status).c_str(),
      paymentMethod.displayName.c_str(),
      amount, getTotalWithFees());
    }
};


int main(){
  Order order("ORD-001", PaymentMethod::CREDIT_CARD, 99.99);
  order.displayInfo();
  
  order.advanceStatus();
  order.advanceStatus();
  order.displayInfo();
  
  cout << "Cancel after shipping: "<< (order.cancel() ? "true" : "false")<<endl;
  return 0;
}

/*Output:

2 ms | 4.5 MB
Order ORD-001 | Status: PLACED | Payment: CREDIT CARD | Amount: $99.99 (with fees: $102.49)
Order ORD-001 | Status: SHIPPED | Payment: CREDIT CARD | Amount: $99.99 (with fees: $102.49)
Cancel after shipping: false
*/
