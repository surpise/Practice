#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PI;

int n, m;
int arr[101][101];
bool v[101][101];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

void init(){
  cin >> n >> m;
  for(int r = 0; r < n; r++){
    for(int c = 0; c < m; c++) cin >> arr[r][c];
  }
}

void solution(){
  int time = 0, size = 0;
  queue<PI> q;
  queue<PI> tmp;

  q.push({0, 0});
  v[0][0] = true;

  while(!q.empty()){
    int _r = q.front().first;
    int _c = q.front().second;

    q.pop();

    for(int idx = 0; idx < 4; idx++){
      int dr = _r + d[0][idx];
      int dc = _c + d[1][idx];

      if(dr < 0 || dc < 0 || dr >= n || dc >= m) continue;

      if(!v[dr][dc]){
        v[dr][dc] = true;
        if(arr[dr][dc])tmp.push({dr, dc});
        else q.push({dr, dc});
      }
    }

    if(q.empty()){
      if(tmp.empty()){
        cout << time << '\n' << size;
        return;
      }

      time++;
      size = tmp.size();

      while(!tmp.empty()){
        q.push({tmp.front().first, tmp.front().second});
        arr[tmp.front().first][tmp.front().second] = 0;
        tmp.pop();
      }
    }
  }

}

int main(){
  init();

  solution();
}