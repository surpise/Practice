#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define INF 1000000000

using namespace std;

vector<pair<int, int>> graph[1001];
int d[1001];
int stopOver[1001];
int n, m, startN, endN;

class cmp{
  public:
    bool operator()(pair<int, int> a, pair<int, int> b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int u, v, w;
  for(int idx = 0; idx < m; idx++){
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  cin >> startN >> endN;

  for(int idx = 1; idx <= n; idx++) d[idx] = INF;
  d[startN] = 0;
}

void dijkstra(){
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push({startN, 0});

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
        stopOver[next] = cur;
        pq.push({next, nextDist});
      }
    }
  }
}

int main(){
  init();

  dijkstra();

  cout << d[endN] << '\n';

  int stopN = endN;
  stack<int> st;
  st.push(stopN);
  while(stopN != startN){
    stopN = stopOver[stopN];
    st.push(stopN);
  }

  cout << st.size() << '\n';

  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
}