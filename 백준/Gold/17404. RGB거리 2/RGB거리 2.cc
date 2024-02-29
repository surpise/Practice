#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, ans = INF;
  int rgb[1000][3], dp[1000][3];

  cin >> n;
  for(int idx = 0; idx < n; idx++) cin >> rgb[idx][0] >> rgb[idx][1] >> rgb[idx][2];

  for(int color = 0; color < 3; color++){
    dp[0][color] = rgb[0][color];
    dp[0][(color + 1) % 3] = INF;
    dp[0][(color + 2) % 3] = INF;

    for(int idx = 1; idx < n; idx++){
      dp[idx][0] = min(dp[idx - 1][1], dp[idx - 1][2]) + rgb[idx][0];
      dp[idx][1] = min(dp[idx - 1][0], dp[idx - 1][2]) + rgb[idx][1];
      dp[idx][2] = min(dp[idx - 1][0], dp[idx - 1][1]) + rgb[idx][2];
    }

    ans = min({ans, dp[n - 1][(color + 1) % 3], dp[n - 1][(color + 2) % 3]});
  }

  cout << ans;
}