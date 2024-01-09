#include <iostream>
#include <deque>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<int> qs;
  bool qsTypes[100000];
  int qsSize;

  cin >> qsSize;

  for(int idx = 0; idx < qsSize; idx++)  cin >> qsTypes[idx];
  
  for(int idx = 0; idx < qsSize; idx++) {
    int inputV;
    cin >> inputV;
  
    if(qsTypes[idx]) continue;
    qs.push_back(inputV);
  }

  int inputLen;
  cin >> inputLen;

  for(int idx = 0; idx < inputLen; idx++) {
    int inputV;
    cin >> inputV;
    
    qs.push_front(inputV);
    cout << qs.back() << " ";
    qs.pop_back();
  }
}