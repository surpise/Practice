#include <iostream>

#define mod 1000000000

using namespace std;

int n;
int dp[101][10];

int main(){
  for(int idx = 1; idx < 10; idx++) dp[1][idx] = 1;
  cin >> n;

  for(int t = 2; t <= n; t++){
    for(int idx = 0; idx < 10; idx++){
      if(idx == 0) dp[t][idx] = dp[t - 1][idx + 1];

      else if(idx == 9) dp[t][idx] = dp[t - 1][idx - 1];
      
      else dp[t][idx] = (dp[t - 1][idx - 1] + dp[t - 1][idx + 1]) % mod; 
    }
  }

  long long ans = 0;
  for(int idx = 0; idx < 10; idx++) ans = (ans + dp[n][idx]) % mod;
  cout << ans;
}