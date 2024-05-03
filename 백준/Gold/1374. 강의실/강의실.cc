#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
pair <int, int> arr[100001];

int main(){
  cin >> n;

  int num, ans = 0;
  for(int idx = 0; idx < n; idx++){
    cin >> num >> arr[idx].first >> arr[idx].second;
  }

  sort(arr, arr + n);

  priority_queue<int, vector<int>, greater<int>> pq;
  for(int idx = 0; idx < n; idx++){
    if(!pq.empty()){
      if(pq.top() > arr[idx].first) ans++;
      else pq.pop();
    }
    else ans++;

    pq.push(arr[idx].second);
  }

  cout << ans;
}