#include <iostream>

using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int main(){
  cin >> n >> k;
  for(int idx = 1; idx <= n; idx++) cin >> w[idx] >> v[idx];
  
  for(int idx = 1; idx <= n; idx++){
    for(int weight = 1; weight <= k; weight++){
      if(w[idx] > weight) dp[idx][weight] = dp[idx - 1][weight];
      else{
        dp[idx][weight] = max(dp[idx - 1][weight], dp[idx - 1][weight - w[idx]] + v[idx]);
      }
    }
  }

  cout << dp[n][k];
}