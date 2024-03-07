#include <iostream>

#define INF 1e9

using namespace std;

int v, e;
int city[401][401];

void init(){
  cin >> v >> e;
  for(int r = 1; r <= v; r++){
    for(int c = 1; c <= v; c++){
      if(r == c) city[r][c] = 0;
      else city[r][c] = INF;
    }
  }

  int a, b, c;
  for(int cnt = 0; cnt < e; cnt++){
    cin >> a >> b >> c;
    city[a][b] = c;
  }
}

void floyd(){
  for(int o = 1; o <= v; o++){
    for(int s = 1; s <= v; s++){
      for(int e = 1; e <= v; e++){
        int tmp = city[s][o] + city[o][e];
        if(city[s][e] > tmp) city[s][e] = tmp;
      }
    }
  }

  int ans = INF;
  for(int r = 1; r <= v; r++){
    for(int c = 1; c <= v; c++) {
      if(r == c) continue;
      int tmp = city[r][c] + city[c][r];
      if(ans > tmp) ans = tmp;
    }
  }

  if(ans >= INF) cout << -1;
  else cout << ans;
}

int main(){
  init();

  floyd();
}