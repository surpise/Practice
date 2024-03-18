#include <iostream>
#include <algorithm>


using namespace std;

int main(){
  int n, ans = 0;
  cin >> n;

  int t[16] = {0, }, p[16] = {0, }, dp[25] = {0, };
  for(int idx = 1; idx <= n; idx++){
    cin >> t[idx] >> p[idx];
  }

  for(int idx = 1; idx <= n; idx++){
    dp[t[idx] + idx - 1] = max(dp[t[idx] + idx - 1], ans + p[idx]);
    if(ans < dp[idx]) ans = dp[idx];
  }

  cout << ans;
}