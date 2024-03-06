#include <iostream>

#define INF 1e9

using namespace std;

int n, m;
int d[101][101];

void init(){
  cin >> n >> m;

  for(int row = 1; row <= n; row++){
    for(int col = 1; col <= n; col++){
      if(row == col) d[row][col] = 0;
      else d[row][col] = INF;
    }
  }

  int a, b, c;
  for(int cnt = 0; cnt < m; cnt++){
    cin >> a >> b >> c;
    if(c < d[a][b]) d[a][b] = c;
  }
}

void floyd(){
  for(int v = 1; v <= n; v++){
    for(int s = 1; s <= n; s++){
      for(int e = 1; e <= n; e++){
        if(d[s][e] > d[s][v] + d[v][e]) d[s][e] = d[s][v] + d[v][e];
      }
    }
  }

  for(int row = 1; row <= n; row++){
    for(int col = 1; col <= n; col++) {
      if(d[row][col] >= INF) cout << 0 << " ";
      else cout << d[row][col] << " ";
    }
    cout << '\n';
  }
}

int main(){
  init();

  floyd();
}