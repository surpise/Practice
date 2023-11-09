#include <iostream>
#include <deque>

using namespace std;

int main(){
  int n, x;
  deque<pair<int, int>> dq;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    dq.push_back({i + 1, x});
  }

  while(!dq.empty()){
    pair<int, int> bomb = dq.front();
    dq.pop_front();
    cout << bomb.first << " ";
    if(bomb.second > 0){
      for(int i = 0; i < bomb.second - 1; i++){
        dq.push_back(dq.front());
        dq.pop_front();
      }
    }
    else{
      for(int i = 0; i > bomb.second; i--){
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
}