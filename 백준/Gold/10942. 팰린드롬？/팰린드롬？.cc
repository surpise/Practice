#include <iostream>

using namespace std;

int n, m;
int arr[2001];
int dp[2001][2001];

void init(){
  cin >> n;
  for(int idx = 1; idx <= n; idx++) cin >> arr[idx];

  for(int idx = 1; idx <= n; idx++){
    dp[idx][idx] = 1;

    if(idx < n && arr[idx] == arr[idx + 1]) dp[idx][idx + 1] = 1;
  }

  for(int sz = 2; sz <= n - 1; sz++){
    for(int i = 1; i <= n - sz; i++){
      int j = i + sz;
      if((arr[i] == arr[j]) && (dp[i + 1][j - 1]))dp[i][j] = 1;
    }
  }

  cin >> m;
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  init();

  int sn, en;
  for(int i = 0; i < m; i++){
    cin >> sn >> en;

    cout << dp[sn][en] << '\n';
  }
}