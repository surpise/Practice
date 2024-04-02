#include <iostream>
#include <vector>
#include <queue>

#define INF 10000000001

using namespace std;

int n, m;
bool cam[100000];
long long d[100000];
vector<pair<int, long long>> vec[1000000];

class cmp{
  public:
    bool operator()(pair<int, long long> a, pair<int, long long> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  for(int idx = 0; idx < n; idx++) {
    cin >> cam[idx];
    d[idx] = INF;
  }
  d[0] = 0;

  int a, b, t;
  for(int l = 0; l < m; l++){
    cin >> a >> b >> t;
    
    vec[a].push_back({b, t});
    vec[b].push_back({a, t});
  }
}

void dijkstra(){
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;
  pq.push({0, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    long long dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < vec[cur].size(); idx++){
      int next = vec[cur][idx].first;
      long long nextDist = vec[cur][idx].second + dist;

      if(next != n - 1 && cam[next] == 1) continue;

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

  if(d[n - 1] == INF) cout << -1;
  else cout << d[n - 1];
}