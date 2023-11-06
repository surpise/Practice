#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, order, x;
  stack <int> s;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> order;
    switch(order){
      case 1:
        cin >> x;
        s.push(x);
        break;
      case 2:
        if(s.empty()){
          cout << -1 << '\n';
        }
        else{
          cout << s.top() << '\n';
          s.pop();
        }
        break;
      case 3:
        cout << s.size() << '\n';
        break;
      case 4:
        if(s.empty()){
          cout << 1 << '\n';
        }
        else{
          cout << 0 << '\n';
        }
        break;
      case 5:
        if(s.empty()){
          cout << -1 << '\n';
        }
        else{
          cout << s.top() << '\n';
        }
        break;
    }
  }
}