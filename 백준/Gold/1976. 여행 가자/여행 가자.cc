#include <iostream>
#include <queue>

using namespace std;

int n, m;
int city[201][201];
int dist[1000];

void init(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) {
      cin >> city[i][j];
      if(i == j) city[i][j] = 1;
    }
  }

  for(int i = 0; i < m; i++) cin >> dist[i];
}

bool bfs(int sCity, int eCity){
  bool visited[201] = {0, };

  queue<int> q;
  q.push(sCity);
  visited[sCity] = true;

  while(!q.empty()){
    int curCity = q.front();
    q.pop();

    for(int idx = 1; idx <= n; idx++){
      if(!city[curCity][idx]) continue;

      if(idx == eCity) return true;

      if(!visited[idx]){
        q.push(idx);
        visited[idx] = true;
      }
    }
  }

  return false;
}

int main(){
  init();

  bool res = true;
  for(int i = 1; i < m; i++){
    res = bfs(dist[i - 1], dist[i]);

    if(!res) {
      res = false;
      break;
    }
  }

  if(res) cout << "YES";
  else cout << "NO";
}