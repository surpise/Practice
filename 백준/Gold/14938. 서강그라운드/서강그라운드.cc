#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m, r, ans = 0;
vector<pair<int, int>> ground[101];
int d[101];
int itemOfNode[101];

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m >> r;

  for(int idx = 1; idx <= n; idx++) cin >> itemOfNode[idx];

  int a, b, l;
  for(int cnt = 0; cnt < r; cnt++){
    cin >> a >> b >> l;
    ground[a].push_back({b, l});
    ground[b].push_back({a, l});
  }  
}

void dijkstra(int startN){
  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[startN] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({startN, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < ground[cur].size(); idx++){
      int next = ground[cur][idx].first;
      int nextDist = ground[cur][idx].second + dist;

      if(d[next] > nextDist){
        d[next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

void calcItems(){
  int sum = 0;
  for(int idx = 1; idx <= n; idx++){
    if(d[idx] > m) continue;
    sum += itemOfNode[idx];
  }

  if(sum > ans) ans = sum;
}

int main(){
  init();

  for(int idx = 1; idx <= n; idx++){
    dijkstra(idx);
    calcItems();
  }

  cout << ans;
}