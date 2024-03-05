#include <iostream>

using namespace std;

int n;
int arr[1001], dp[1001];
int main(){
  cin >> n;
  for(int idx = 1; idx <= n; idx++) cin >> arr[idx]; 

  int t;
  for(int i = n; i >= 1; i--){
    t = 0;

    for(int j = n; j >= i; j--){
      if(arr[j] < arr[i]) t = max(dp[j], t);
    }

    dp[i] = t + 1;
  }

  int ans = 0;
  for(int idx = 1; idx <= n; idx++){
    if(ans < dp[idx]) ans = dp[idx];
  }

  cout << ans;
}