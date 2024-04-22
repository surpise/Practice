#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
  int ans = 0;
  string s, t;
  cin >> s >> t;

  queue<int> q[27];

  int sSize = s.size(), tSize = t.size();
  for(int idx = 0; idx < sSize; idx++){
    q[s[idx] - 'a'].push(idx);
  }

  bool flag = true;

  while(flag){
    int tmp = -1;
    int len = 0;
    for(int idx = 0; idx < tSize; idx++){
      int alpha = t[idx] - 'a';

      if(q[alpha].empty()){
        flag = false;
        break;
      }

      while(!q[alpha].empty()){
        if(q[alpha].front() > tmp){
          tmp = q[alpha].front();
          q[alpha].pop();
          len++;
          break;
        }

        q[alpha].pop();
      }

      if(len == tSize){
        ans++;
        break;
      }
    }
  }

  cout << ans;
}
