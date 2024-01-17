#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[1001];
int d[1001][1001];
int n, m, x;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m >> x;

  int s, e, w;
  for(int idx = 0; idx < m; idx++){
    cin >> s >> e >> w;
    graph[s].push_back({e, w});
  }

  for(int nIdx = 1; nIdx <= n; nIdx++){
    for(int idx = 1; idx <= n; idx++) d[nIdx][idx] = INF;
  }
}

void dijkstra(int v){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({v, 0});
  d[v][v] = 0;

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(d[v][cur] < dist) continue;

    for(int idx = 0; idx < graph[cur].size(); idx++){
      int next = graph[cur][idx].first;
      int nextDist = graph[cur][idx].second + dist;

      if(d[v][next] > nextDist){
        d[v][next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

int main(){
  init();

  for(int idx = 1; idx <= n; idx++) dijkstra(idx);

  int ans = 0, tmp;
  for(int idx = 1; idx <= n; idx++){
    tmp = d[idx][x] + d[x][idx];
    if(tmp > ans) ans = tmp;
  }  
  cout << ans;
}
