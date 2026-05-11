#include<bits/stdc++.h>
using namespace std;

struct HttpStatus{
  int code ;
  string message;
  
  static const HttpStatus OK;
  static const HttpStatus BAD_REQUEST;
  static const HttpStatus NOT_FOUND;
  static const HttpStatus INTERNAL_SERVER_ERROR;
  
  bool isSuccess() const{
    return code < 400;
  }
  
  void display() const{
    cout << code<< " "<< message <<endl;
  }
  
  static const HttpStatus* fromCode(int code){
    for(const auto* status : values()) {
      if(status->code == code){
        return status;
      }
    }
    return nullptr;
  }
  
  static const vector<const HttpStatus*> &values(){
    static vector<const HttpStatus*> v= {&OK ,&BAD_REQUEST,&NOT_FOUND, &INTERNAL_SERVER_ERROR};
    return v;
    } 
};

const HttpStatus HttpStatus::OK{200, "OK"};
const HttpStatus HttpStatus::BAD_REQUEST{400,"BAD_REQUEST"};
const HttpStatus HttpStatus::NOT_FOUND{404,"NOT_FOUND"};
const HttpStatus HttpStatus::INTERNAL_SERVER_ERROR{500,"INTERNAL_SERVER_ERROR"};


int main(){
  HttpStatus::OK.display();
  HttpStatus::NOT_FOUND.display();
  
  cout<< "Is 200 success?" << (HttpStatus::OK.isSuccess() ? "true" : "false") << endl;
  cout<< "Is 404 success?" << (HttpStatus::NOT_FOUND.isSuccess() ? "true" : "false") << endl;
  const HttpStatus* found = HttpStatus::fromCode(500);
    if (found != nullptr) {
        cout << "Found by code 500: ";
        found->display();
    }
  return 0;
}
