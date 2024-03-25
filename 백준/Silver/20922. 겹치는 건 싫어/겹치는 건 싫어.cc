#include <iostream>
#include <algorithm>
#include <queue>

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
  queue<int> q;

  int res = 0;
  int l = 0, r = 0;

  while(l <= r){
    if(r >= n || l >= n) break;

    if(cnt[arr[r]] < k){
          cnt[arr[r]]++;
      q.push(arr[r]);
      r++;
    }
    
    else{
      cnt[q.front()]--;
      q.pop();
      l++;
    }

    if(q.size() > res) res = q.size();
  }

  return res;
}

int main(){
  init();

  cout << solution();
}