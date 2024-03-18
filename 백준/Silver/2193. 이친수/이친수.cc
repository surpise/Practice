#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  long long dp[91] = {0, 1, 1, 0, };
  for(int idx = 3; idx <= n; idx++){
    dp[idx] = dp[idx - 1] + dp[idx - 2];
  }

  cout << dp[n];
}