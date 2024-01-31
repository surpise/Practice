#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<pair<int, int>, int> coordAndWall;

int n, m;
int maze[101][101];
int d[101][101];
int drc[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

class cmp{
  public:
    bool operator()(coordAndWall a, coordAndWall b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n >> m;

  string mazeR;
  for(int r = 1; r <= m; r++){
    cin >> mazeR;
    for(int c = 1; c <= n; c++){
      maze[r][c] = mazeR[c - 1] - '0';
      d[r][c] = INF;
    }
  }

  d[1][1] = 0;
}

void dijkstra(){
  priority_queue<coordAndWall, vector<coordAndWall>, cmp> pq;
  pq.push({{1, 1}, 0});

  while(!pq.empty()){
    int curR = pq.top().first.first;
    int curC = pq.top().first.second;
    int dist = pq.top().second;
    pq.pop();

    if(d[curR][curC] < dist) continue;

    for(int idx = 0; idx < 4; idx++){
      int nextR = curR + drc[0][idx];
      int nextC = curC + drc[1][idx];

      if(nextR <= 0 || nextR > m || nextC <= 0 || nextC > n) continue;

      int nextDist = maze[nextR][nextC] + dist;

      if(d[nextR][nextC] > nextDist){
        d[nextR][nextC] = nextDist;
        pq.push({{nextR, nextC}, nextDist});
      }
    }
  }
}

int main(){
  init();
  
  dijkstra();

  cout << d[m][n];
}