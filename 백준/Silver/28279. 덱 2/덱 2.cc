#include <iostream>
#include <deque>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  deque<int> dq;
  int n, ord, x;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> ord;
    switch(ord){
      case 1:
        cin >> x;
        dq.push_front(x);
        break;
      case 2:
        cin >> x;
        dq.push_back(x);
        break;
      case 3:
        if(!dq.empty()){
          cout << dq.front() << '\n';
          dq.pop_front();
        }
        else{
          cout << -1 << '\n';
        }
        break;
      case 4:
        if(!dq.empty()){
          cout << dq.back() << '\n';
          dq.pop_back();
        }
        else{
          cout << -1 << '\n';
        }
        break;
      case 5:
        cout << dq.size() << '\n';
        break;
      case 6:
        cout << int(dq.empty()) << '\n';
        break;
      case 7:
        cout << (dq.empty() ? -1 : dq.front()) << '\n';
        break;
      case 8:
        cout << (dq.empty() ? -1 : dq.back()) << '\n';
        break;
    }
  }
}