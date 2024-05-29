#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int x[100000], y[100000];
int mx, my;

void init(){
  cin >> n >> m;

  for(int idx = 0; idx < m; idx++) cin >> x[idx] >> y[idx];
  
  sort(x, x + m);
  sort(y, y + m);

  mx = x[m / 2];
  my = y[m / 2];
}

int main(){
  init();

  int ans = 0;
  for(int idx = 0; idx < m; idx++){
    ans += abs(x[idx] - mx);
    ans += abs(y[idx] - my);
  }
  
  cout << ans;
}