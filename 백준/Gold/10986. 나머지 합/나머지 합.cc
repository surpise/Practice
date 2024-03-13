#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  long long sum = 0;
  long long mod[1001] = {0, };
  vector<long long> arr;
  arr.push_back(0);

  cin >> n >> m;

  int a;
  for(int idx = 1; idx <= n; idx++){
    cin >> a;
    sum += a;
    arr.push_back(sum % m);
    mod[arr[idx]]++;
  }

  long long ans = mod[0];
  for(int i = 0; i < m; i++) ans += mod[i] * (mod[i] - 1) / 2;

  cout << ans;
}