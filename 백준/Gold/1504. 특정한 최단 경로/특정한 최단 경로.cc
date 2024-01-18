#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[801];
int d[801];
int n, e, u, v;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> e;

  int a, b, c;
  for(int idx = 0; idx < e; idx++){
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  cin >> u >> v;
}

void dijkstra(int x){
  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[x] = 0;

  priority_queue<pair<int, int>> pq;
  pq.push({x, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < graph[cur].size(); idx++){
      int next = graph[cur][idx].first;
      int nextDist = graph[cur][idx].second + dist;

      if(d[next] > nextDist){
        d[next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

int main(){
  init();

  dijkstra(1);
  int track1 = d[u];
  int track2 = d[v];

  dijkstra(u);
  if(d[v] == INF) track1 = INF;
  else track1 += d[v];

  if(d[n] == INF) track2 = INF; 
  else track2 += d[n];

  dijkstra(v);
  if(d[u] == INF) track2 = INF;
  else track2 += d[u];
  
  if(d[n] == INF) track1 = INF;
  else track1 += d[n];

  if(track1 >= INF && track2 >= INF) cout << -1;
  else if(track1 < track2) cout << track1;
  else cout << track2;
}