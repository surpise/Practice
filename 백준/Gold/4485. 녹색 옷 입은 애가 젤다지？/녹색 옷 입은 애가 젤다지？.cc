#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<pair<int, int>, int> coordWithRupee;

int cave[125][125];
int d[125][125];
int drc[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int n;

class cmp{
  public:
    bool operator()(coordWithRupee a, coordWithRupee b){
      return a.second > b.second;
    }
};

void init(){
  for(int row = 0; row < n; row++){
    for(int col = 0; col < n; col++) {
      cin >> cave[row][col];
      d[row][col] = INF;
    }
  }

  d[0][0] = cave[0][0];
}

void dijkstra(){
  priority_queue<coordWithRupee, vector<coordWithRupee>, cmp> pq;
  pq.push({{0, 0}, cave[0][0]});

  while(!pq.empty()){
    int curR = pq.top().first.first;
    int curC = pq.top().first.second;
    int rupee = pq.top().second;
    pq.pop();
    
    if(d[curR][curC] < rupee) continue;

    for(int idx = 0; idx < 4; idx++){
      int nextR = curR + drc[0][idx];
      int nextC = curC + drc[1][idx];

      if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;

      int nextRupee = cave[nextR][nextC] + rupee;
      if(d[nextR][nextC] > nextRupee){
        d[nextR][nextC] = nextRupee;
        pq.push({{nextR, nextC}, nextRupee});
      }
    }
  }
}

int main(){
  int cnt = 1;

  while(1){
    cin >> n;
    if(n == 0) break;

    init();

    dijkstra();

    cout << "Problem " << cnt << ": " << d[n - 1][n - 1] << '\n';
    cnt++;
  }
}