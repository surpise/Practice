#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m;
vector<pair<int ,int>> graph[50001];
int d[50001];

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int a_i, b_i, c_i;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a_i >> b_i >> c_i;
    graph[a_i].push_back({b_i, c_i});
    graph[b_i].push_back({a_i, c_i});
  };

  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[1] = 0;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({1, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    int crop = pq.top().second;
    pq.pop();

    if(d[cur] < crop) continue;

    for(int idx = 0; idx < graph[cur].size(); idx++){
      int next = graph[cur][idx].first;
      int nextCrop = graph[cur][idx].second + crop;

      if(d[next] > nextCrop){
        d[next] = nextCrop;
        pq.push({next, nextCrop});
      }
    }
  }
}

int main(){
  init();

  dijkstra();

  cout << d[n];
}