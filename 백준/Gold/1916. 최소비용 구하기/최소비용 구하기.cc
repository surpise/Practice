#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[1001];
int d[1001];
int n, m, startCity, endCity;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int s, e, w;
  for(int idx = 0; idx < m; idx++){
    cin >> s >> e >> w;
    graph[s].push_back({e, w});
  }

  for(int idx = 1; idx <= n; idx++) d[idx] = INF;

  cin >> startCity >> endCity;
  d[startCity] = 0;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({startCity, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(dist > d[cur]) continue;

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
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  init();

  dijkstra();

  cout << d[endCity];
}