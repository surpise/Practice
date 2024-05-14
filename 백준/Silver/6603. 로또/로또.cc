#include <iostream>

using namespace std;

int k;
int arr[13], res[6];

void search(int depth, int len){
  if(len == 6){
    for(int idx = 0; idx < 6; idx++) cout << res[idx] << " ";
    cout << '\n';
    
    return;
  }

  for(int idx = depth; idx < k; idx++){
    res[len] = arr[idx];

    search(idx + 1, len + 1);
  }
}

int main(){
  while(1){
    cin >> k;

    if(k == 0) break;

    for(int idx = 0; idx < k; idx++) cin >> arr[idx];

    search(0, 0);

    cout << '\n';
  }
}