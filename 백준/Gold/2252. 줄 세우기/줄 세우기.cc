#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> students[32001];
int enternodes[32001] = {0, };
queue<int> q;

void init(){
  cin >> n >> m;

  int a, b;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a >> b;
    students[a].push_back(b);
    enternodes[b]++;
  }

  for(int idx = 1; idx <= n; idx++){
    if(!enternodes[idx]) q.push(idx);
  }
}

void solution(){
  vector<int> res;

  while(!q.empty()){
    int tmp = q.front();
    res.push_back(tmp);
    q.pop();

    for(int idx = 0; idx < students[tmp].size(); idx++){
      int next = students[tmp][idx];
      enternodes[next]--;
      if(!enternodes[next]) q.push(next);
    }
  }

  for(int idx = 0; idx < res.size(); idx++) cout << res[idx] << " ";
}

int main(){
  init();

  solution();
}