#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[2001];

bool search(int idx){
  int left = 0, right = n - 1;

  while(left < right){
    if(left == idx) left++;

    else if(right == idx) right--;

    else if(arr[idx] == arr[left] + arr[right]) return true;
    
    else if(arr[idx] > arr[left] + arr[right]) left++;
    
    else if(arr[idx] < arr[left] + arr[right]) right--;
  }
  return false;
}

void solution(){
  cin >> n;

  for(int idx = 0; idx < n; idx++) cin >> arr[idx];
  sort(arr, arr + n);

  int ans = 0;
  for(int idx = 0; idx < n; idx++){
    if(search(idx)) ans++;
  }

  cout << ans;
}

int main(){
  solution();
}