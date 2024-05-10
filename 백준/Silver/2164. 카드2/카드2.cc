#include <iostream>
#include <queue>

using namespace std;

int main(){
  int n;
  cin >> n;

  queue<int> q;
  for(int idx = 1; idx <= n; idx++) q.push(idx);

  while(q.size() > 1){
    q.pop();

    int tmp = q.front();
    q.push(tmp);
    q.pop();
  }

  cout << q.front();
}