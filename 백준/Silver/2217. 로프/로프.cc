#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> n;

  vector<int> vec;
  for(int idx = 0; idx < n; idx++){
    cin >> k;
    vec.push_back(k);
  }

  sort(vec.begin(), vec.end(), greater<int>());

  int res = 0;
  for(int idx = 0; idx < n; idx++){
    if(res < vec[idx] * (idx + 1)) res = vec[idx] * (idx + 1);
  }

  cout << res;
}