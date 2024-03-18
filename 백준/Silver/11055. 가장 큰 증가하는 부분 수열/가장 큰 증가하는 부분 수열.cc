#include <iostream>

using namespace std;

int main(){
  int n, ans = 0;
  cin >> n;

  int arr[1001] = {0, };
  for(int idx = 1; idx <= n; idx++) cin >> arr[idx];

  int dp[1001] = {0, };
  for(int idx = 1; idx <= n; idx++){
    dp[idx] = arr[idx];
    for(int cmpIdx = 1; cmpIdx < idx; cmpIdx++){
      if(arr[cmpIdx] < arr[idx] && dp[idx] < arr[idx] + dp[cmpIdx]){
        dp[idx] = arr[idx] + dp[cmpIdx];
      }
    }

    if(ans < dp[idx]) ans = dp[idx];
  }
  
  cout << ans;
}

