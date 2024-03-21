#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;

  int arr[1000];
  for(int idx = 0; idx < n; idx++) cin >> arr[idx];
  
  sort(arr, arr + n);

  int sum = 1;
  for(int idx = 0; idx < n; idx++){
    if(arr[idx] > sum) break;

    sum += arr[idx];
  }

  cout << sum;
}