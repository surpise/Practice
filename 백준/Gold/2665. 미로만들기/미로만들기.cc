#include <iostream>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<pair<int, int>, int> coordWithColor;

int maze[51][51];
int d[51][51];
int dcr[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int n;

class cmp{
  public:
    bool operator()(coordWithColor a, coordWithColor b){
      return a.second > b.second;
    }
};

void init(){
  cin >> n;

  string colorRow;
  bool color;
  for(int row = 1; row <= n; row++){
    cin >> colorRow;
    for(int col = 1; col <= n; col++){
      color = colorRow[col - 1] - '0';
      maze[row][col] = !color;
      d[row][col] = INF;
    }
  }

  d[1][1] = maze[1][1];
}

void dijkstra(){
  priority_queue<coordWithColor, vector<coordWithColor>, cmp> pq;
  pq.push({{1, 1}, maze[1][1]});

  while(!pq.empty()){
    int curR = pq.top().first.first;
    int curC = pq.top().first.second;
    int color = pq.top().second;
    pq.pop();

    if(d[curR][curC] < color) continue;

    for(int idx = 0; idx < 4; idx++){
      int nextR = curR + dcr[0][idx];
      int nextC = curC + dcr[1][idx];

      if(nextR <= 0 || nextR > n || nextC <= 0 || nextC > n) continue;

      int changedColorCnt = maze[nextR][nextC] + color;
      if(d[nextR][nextC] > changedColorCnt){
        d[nextR][nextC] = changedColorCnt;
        pq.push({{nextR, nextC}, changedColorCnt});
      }
    }
  }
}

int main(){
  init();

  dijkstra();

  cout << d[n][n];
}