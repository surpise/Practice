#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000000

using namespace std;

int n, m, k, x;
vector<pair<int, int>> graph[300001];
long long d[300001];

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m >> k >> x;

  int a, b;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a >> b;
    graph[a].push_back({b, 1});
  }

  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[x] = 0;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({x, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    long long dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < graph[cur].size(); idx++){
      int next = graph[cur][idx].first;
      long long nextDist = graph[cur][idx].second + dist;

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

  int sum = 0;
  for(int idx = 1; idx <= n; idx++){
    if(d[idx] == k) {
      cout << idx << '\n';
      sum++;
    }
  }

  if(!sum) cout << -1;
}