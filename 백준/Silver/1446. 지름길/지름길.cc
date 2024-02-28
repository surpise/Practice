#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, D;
int d[10001];
vector<pair<int, int>> graph[10001];

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> N >> D;
  
  int s, e, l;
  for(int cnt = 0; cnt < N; cnt++){
    cin >> s >> e >> l;
    graph[s].push_back({e, l});
  }

  for(int idx = 0; idx <= D; idx++) graph[idx].push_back({idx + 1, 1});

  for(int idx = 0; idx < 10001; idx++) d[idx] = INF;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({0, 0});
  d[0] = 0;
  
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

  cout << d[D];
}