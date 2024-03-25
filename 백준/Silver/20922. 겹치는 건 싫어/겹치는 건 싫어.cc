#include <iostream>

using namespace std;

int n, k;
int arr[200000];
int cnt[100001];

void init(){
  cin >> n >> k;

  int v, t = 1;
  for(int idx = 0; idx < n; idx++) cin >> arr[idx];
}

int solution(){
  int res = 0;
  int l = 0, r = 0;

  while(l <= r){
    if(r >= n || l >= n) break;

    if(cnt[arr[r]] < k)
    {
      cnt[arr[r]]++;
      r++;
    } 

    else{
      cnt[arr[l]]--;
      l++;
    }

    res = max(res, r - l);
  }

  return res;
}

int main(){
  init();

  cout << solution();
}