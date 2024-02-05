#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int t, n, d, c;
vector<pair<int, int>> network[10001];
int hacked[10001];

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> d >> c;

  for(int idx = 1; idx <= n; idx++) {
    network[idx].clear();
    hacked[idx] = INF;
  }

  int a, b, s;
  for(int cnt = 0; cnt < d; cnt++){
    cin >> a >> b >> s;
    network[b].push_back({a, s});
  }
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({c, 0});
  hacked[c] = 0;

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(hacked[cur] < dist) continue;

    for(int idx = 0 ; idx < network[cur].size(); idx++){
      int next = network[cur][idx].first;
      int nextDist = network[cur][idx].second + dist;

      if(hacked[next] > nextDist){
        hacked[next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

int main(){
  cin >> t;
  for(int cnt = 0; cnt < t; cnt++){
    init();

    dijkstra();

    int hackedCom = 0;
    int time = 0;;

    for(int idx = 1; idx <= n; idx++){
      if(hacked[idx] == INF) continue;
      
      hackedCom++;
      if(hacked[idx] > time) time = hacked[idx];
    }

    cout << hackedCom << " " << time << '\n';
  }
}