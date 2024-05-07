#include <iostream>

using namespace std;

int n, m;
int train[50001];
int dp[3][50001];

void init(){
  cin >> n;

  cin >> train[1];
  for(int idx = 2; idx <= n; idx++) {
    cin >> train[idx];
    train[idx] += train[idx - 1];
  }

  cin >> m;
}

int main(){
  init();

  for(int idx = m; idx <= n; idx++){
    dp[0][idx] = max(dp[0][idx - 1], train[idx] - train[idx - m]);
  }

  for(int num = 1; num < 3; num++){
    for(int idx = m + num * m; idx <= n; idx++){
      dp[num][idx] = max(dp[num][idx - 1], dp[num - 1][idx - m] +  train[idx] - train[idx - m]);
    }
  }

  cout << dp[2][n];
}