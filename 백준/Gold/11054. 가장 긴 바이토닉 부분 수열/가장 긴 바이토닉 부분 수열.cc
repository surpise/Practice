#include <iostream>

using namespace std;

int n;
int arr[1001], dpb[1001], dps[1001];
int main(){
  cin >> n;
  for(int idx = 1; idx <= n; idx++) cin >> arr[idx]; 

  int t;
  for(int i = 1; i <= n; i++){
    t = 0;

    for(int j = 0; j <= i; j++){
      if(arr[j] < arr[i]) t = max(dpb[j], t);
    }

    dpb[i] = t + 1;
  }

  for(int i = n; i >= 1; i--){
    t = 0;

    for(int j = n; j >= i; j--){
      if(arr[j] < arr[i]) t = max(dps[j], t);
    }

    dps[i] = t + 1;
  }

  int ans = 0;
  for(int idx = 1; idx <= n; idx++){
    int tmp = dpb[idx] + dps[idx] - 1;
    if(ans < tmp) ans = tmp;
  }

  cout << ans;

}