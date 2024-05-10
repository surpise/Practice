#include <iostream>
#include <stack>

using namespace std;

int main(){
  int n;
  cin >> n;

  int t = 1;
  stack<int> st;

  int v;
  for(int idx = 0; idx < n; idx++){
    cin >> v;
    if(v != t){
      while(!st.empty()){
        if(st.top() == t){
          t++;
          st.pop();
        }
        else break;
      }
      st.push(v);
    }
    else t++;
  }
  while(!st.empty()){
    if(st.top() == t){
      t++;
      st.pop();
    }
    else break;
  }

  if(!st.empty()) cout << "Sad";
  else cout << "Nice";
}