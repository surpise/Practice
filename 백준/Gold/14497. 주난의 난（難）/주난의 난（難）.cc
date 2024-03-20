#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int n, m;
int arr[301][301];
int d[301][301];
PII junan, thief;

class cmp{
  public:
    bool operator()(PIII a, PIII b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  int x, y;
  cin >> x >> y;
  junan = {x, y};

  cin >> x >> y;
  thief = {x, y};

  string str;  
  for(int r = 1; r <= n; r++){
    cin >> str;

    for(int c = 1; c <= m; c++){
      d[r][c] = INF;

      if(str[c - 1] == '#') arr[r][c] = 1;

      else if(str[c - 1] == '*') arr[r][c] = 0;

      else arr[r][c] = str[c - 1] - '0';
    }
  }
}

void dijkstra(){
  int drc[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
  priority_queue<PIII, vector<PIII>, cmp> pq;
  pq.push({{junan.first, junan.second}, 0});

  while(!pq.empty()){
    int curR = pq.top().first.first;
    int curC = pq.top().first.second;
    int jump = pq.top().second;
    pq.pop();

    if(d[curR][curC] < jump) continue;

    for(int idx = 0; idx < 4; idx++){
      int nextR = curR + drc[0][idx];
      int nextC = curC + drc[1][idx];

      if(nextR <= 0 || nextR > n || nextC <= 0 || nextC > m) continue;

      int nextJump = jump + arr[nextR][nextC];
      if(d[nextR][nextC] > nextJump){
        d[nextR][nextC] = nextJump;
        pq.push({{nextR, nextC}, nextJump});
      }
    }
  }
}

int main(){
  init();

  dijkstra();

  cout << d[thief.first][thief.second];
}