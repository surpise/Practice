#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, sum = 0;
int m[101], c[101];
int dp[101][10001];

int main(){
  cin >> N >> M;

  for(int idx = 1; idx <= N; idx++) cin >> m[idx];
  
  for(int idx = 1; idx <= N; idx++) {
    cin >> c[idx];
    sum += c[idx];
  }

  for(int idx = 1; idx <= N; idx++){
    for(int memIdx = 0; memIdx <= sum; memIdx++){
      if(c[idx] > memIdx) dp[idx][memIdx] = dp[idx - 1][memIdx];
      else dp[idx][memIdx] = max(dp[idx - 1][memIdx], dp[idx - 1][memIdx - c[idx]] + m[idx]);
    }
  }

  for(int idx = 0; idx <= sum; idx++){
    if(dp[N][idx] >= M){
      cout << idx;
      break;
    }
  }
}