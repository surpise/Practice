#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[201];
int ans[201][201];
int d[201];
int prevN[201];
int n, m;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int u, v, w;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
}

void dijkstra(int startN){
  for(int idx = 1; idx <= n; idx++) prevN[idx] = startN;
  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[startN] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({startN, 0});

  while(!pq.empty()){
    int cur = pq.top().first;
    int dist = pq.top().second;
    pq.pop();

    if(d[cur] < dist) continue;

    for(int idx = 0; idx < graph[cur].size(); idx++){
      int next = graph[cur][idx].first;
      int nextDist = graph[cur][idx].second + dist;

      if(d[next] > nextDist){
        prevN[next] = cur;
        d[next] = nextDist;
        pq.push({next, nextDist});
      }
    }
  }
}

void getTableData(int row){
  for(int idx = 1; idx <= n; idx++){
    if(row == idx){
      ans[row][idx] = -1;
      continue;
    }

    int prev = prevN[idx];
    while(1){
      if(prev == row){
        ans[row][idx] = idx;
        break;
      }
      
      if(prevN[prev] == row){
        ans[row][idx] = prev;
        break;
      }

      prev = prevN[prev];
    }
  }
}

int main(){
  init();

  for(int idx = 1; idx <= n; idx++){
    dijkstra(idx);

    getTableData(idx);
  }

  for(int row = 1; row <= n; row++){
    for(int col = 1; col <= n; col++){
      if(ans[row][col] == -1) cout << "- ";
      else cout << ans[row][col] << ' ';
    }
    cout << '\n';
  }
}