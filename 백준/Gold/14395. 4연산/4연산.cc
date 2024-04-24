#include <iostream>
#include <queue>
#include <set>

#define INF 1000000000

using namespace std;

int s, t;
char code[4] = {'*', '+', '/'};
queue<pair<long long, string>> q;
set<int> sV;

long long calc(long long v, char code){
  switch (code)
  {
  case '*':
    return v * v;
  case '+':
    return v + v;
  case '/':
    return v / v;
  default:
    break;
  }
}

void bfs(){
  q.push({s, ""});
  sV.insert(s);

  while(!q.empty()){
    long long curV = q.front().first;
    string curS = q.front().second;
    q.pop();

    for(int i = 0; i < 3; i++){
      long long nextV = calc(curV, code[i]);
      string nextS = curS + code[i];

      if(nextV > INF) continue;

      if(nextV == t){
        cout << nextS;
        return;
      }

      else if(sV.find(nextV) == sV.end()) {
        q.push({nextV, nextS});
        sV.insert(nextV);
      }
    }
  }

  cout << -1;
}

int main(){
  cin >> s >> t;

  if(s == t) cout << 0;
  else bfs();
}