#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  int arr[10001] = {0, };

  cin >> n;
  for(int idx = 1; idx <= n; idx++) cin >> arr[idx];

  int dp[10001] = {0, };
  dp[1] = arr[1];
  dp[2] = arr[1] + arr[2];
  dp[3] = max({dp[2], arr[1] + arr[3], arr[2] + arr[3]});

  for(int idx = 4; idx <= n; idx++){
    dp[idx] = max({dp[idx - 1], dp[idx - 2] + arr[idx], dp[idx - 3] + arr[idx - 1] + arr[idx]});
  }

  cout << dp[n];
}