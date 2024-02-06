#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000

using namespace std;

int d[2001], tmp[2001];
vector<pair<int, int>> street[2001];
vector<int> target;
int n, m, t, s, g, h;
int smellStreet;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m >> t;
  cin >> s >> g >> h;

  for(int idx = 1; idx <= n; idx++) street[idx].clear();
  target.clear();
  
  int a, b, d;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a >> b >> d;

    if((a == g && b == h) || (a == h && b == g)) smellStreet = d;

    street[a].push_back({b, d});
    street[b].push_back({a, d});
  }

  int x;
  for(int cnt = 0; cnt < t; cnt++){
    cin >> x;
    target.push_back(x);
  }
  sort(target.begin(), target.end());
}

void dijkstra(int v){
  for(int idx = 1; idx <= n; idx++) d[idx] = INF;

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({v, 0});
  d[v] = 0;

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < street[cur].size(); idx++){
      int next = street[cur][idx].first;
      int nextDist = street[cur][idx].second + dist;

      if(d[next] > nextDist){
        d[next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

int main(){
  int testCase;
  cin >> testCase;

  for(int cnt = 0; cnt < testCase; cnt++){
    init();

    dijkstra(s);

    int nextPoint = h;
    if(d[g] > d[h]) nextPoint = g;
    int sgh = d[nextPoint];

    for(int idx = 1; idx <= n; idx++) tmp[idx] = d[idx];

    dijkstra(nextPoint);

    for(int idx = 0; idx < t; idx++){
      if(tmp[target[idx]] == d[target[idx]] + sgh) cout << target[idx] << " ";
    }
    cout << '\n';
  }
}