#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m;
vector<pair<int, int>> graph[5001];
int d[5001];
int s, t;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int a, b, c;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  cin >> s >> t;

  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[s] = 0;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({s, 0});

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

  dijkstra();

  cout << d[t];
}