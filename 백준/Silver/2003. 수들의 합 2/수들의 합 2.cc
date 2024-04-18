#include <iostream>

using namespace std;

int main(){
  int n, m;
  int arr[10000] = {0, };

  cin >> n >> m;
  
  int v;
  for(int idx = 1; idx <= n; idx++) {
    cin >> v;
    arr[idx] = v + arr[idx - 1];
  }

  int lIdx = 0, rIdx = 1, ans = 0;

  if(arr[lIdx] == m) ans = 1;

  while(lIdx <= rIdx){
    if(rIdx > n) break;

    if(arr[rIdx] - arr[lIdx] <= m){
      if(arr[rIdx] - arr[lIdx] == m) ans++;

      rIdx++;
    }
    else lIdx++;
  }

  cout << ans;
}