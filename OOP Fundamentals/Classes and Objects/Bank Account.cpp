#include<bits/stdc++.h>
using namespace std;

class BankAccount{
private:
  string accountNumber;
  string ownerName;
  double balance;
  
public:
  BankAccount(const string& accountNumber, const string& ownerName)
    : accountNumber(accountNumber),ownerName(ownerName),balance(0) {}
    
  
  void deposit(double amount){
    if(amount>0)
      balance += amount;
  }
  
  bool withdraw(double amount){
    if(amount>0 && balance>=amount){
     balance -= amount;
     return true;
    }
    return false;
  }
  
  double getBalance() const{
    return balance;
  }
};

int main(){
  BankAccount account1("atm01","Gunjan");
  account1.deposit(1000);
  cout << fixed << setprecision(1) << account1.getBalance() << endl;
  

}
