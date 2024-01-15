#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000

vector<pair<int, int>> graph[20001];
int d[20001];
int v, e, k;

void dijkstra(){
  d[k] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, k});

  while(!pq.empty()){
    int cur = pq.top().second;
    int distance = pq.top().first;
    pq.pop();

    if(d[cur] < distance) continue;

    for(int i = 0; i < graph[cur].size(); i++){
      int next = graph[cur][i].second;
      int nextDistance = distance + graph[cur][i].first;

      if(nextDistance < d[next]){
        d[next] = nextDistance;
        pq.push({nextDistance, next});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> v >> e >> k;

  int u1, u2, w;
  for(int i = 0; i < e; i++){
    cin >> u1 >> u2 >> w;
    graph[u1].push_back({w, u2});
  }

  for(int i = 1; i <= v; i++) d[i] = INF;

  dijkstra();

  for(int i = 1; i <= v; i++) {
    if(d[i] == INF) cout << "INF" << '\n';
    else cout << d[i] << '\n';
  }
}