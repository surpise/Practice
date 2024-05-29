#include <iostream>

using namespace std;

int n, m;
int arr[301][301];

int calcSum(int x1, int y1, int x2, int y2){
  int sum = 0;

  for(int r = x1; r <= x2; r++){
    for(int c = y1; c <= y2; c++) sum += arr[r][c];
  }

  return sum;
}

int main(){
  cin >> n >> m;
  for(int r = 1; r <= n; r++){
    for(int c = 1; c <= m; c++) cin >> arr[r][c];
  }

  int cnt;
  cin >> cnt;

  int a, b, c, d;
  for(int idx = 0; idx < cnt; idx++){
    cin >> a >> b >> c >> d;
    cout << calcSum(a, b, c, d) << '\n';
  }
}