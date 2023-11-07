#include <iostream>
#include <stack>

using namespace std;

int main(){
  int sz, cur = 1, v;
  stack<int> s;
  cin >> sz;
  for(int i = 0; i < sz; i++){
    cin >> v;
    if(v != cur){
      while(!s.empty()){
        if(s.top() == cur){
          s.pop();
          cur++;
        }
        else{
          break;
        }
      }
      s.push(v);
    }
    else{
      cur++;
    }
  }
  while(!s.empty()){
    if(s.top() == cur){
      s.pop();
      cur++;
    }
    else{
      break;
    }
  }

  if(s.empty()){
    cout << "Nice";
  }
  else{
    cout << "Sad";
  }
}