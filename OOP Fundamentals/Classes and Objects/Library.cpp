#include<bits/stdc++.h>
using namespace std;

class Book{
private:
  string isbn;
  string author;
  string title;
  bool isAvailable;
  
public:
  Book(const string& author, const string& title,const string&isbn)
    : author(author),title(title),isbn(isbn),isAvailable(false) {}
    
  bool borrowBook(){
    if(isAvailable){
      isAvailable=false;
      return true;
    }else{
      return false;
    }
  }
  
  void returnBook(){
      isAvailable=true;
  }
  
  void displayInfo() const{
     string status = isAvailable ? "Available" : "Borrowed";
     cout << title << " by " << author << " (ISBN: " << isbn << ") - " 
     << status << endl;
  }
};

int main(){
  Book book1("Shreya", "love is the key", "1087Y-01");
  book1.displayInfo();
  
  bool success= book1.borrowBook();
  cout<<" Book Borrow successful" << boolalpha << success<<endl;
  book1.displayInfo();
  
  success = book1.borrowBook();
  cout << "Borrow successful: " << success << endl;

  book1.returnBook();
  book1.displayInfo();
  
  cout<<"----"<<endl;
  return 0;
}
