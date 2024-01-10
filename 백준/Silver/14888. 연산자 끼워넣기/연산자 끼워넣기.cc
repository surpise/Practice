#include <iostream>

using namespace std;

int nums[11], signs[4];
int n, maxSum = -1000000000, minSum = 1000000000;

int calcNum(int signType, int num1, int num2){
  switch (signType)
  {
  case 0:
    return num1 + num2;
  case 1: 
    return num1 - num2;
  case 2: 
    return num1 * num2;
  case 3:
    return num1 / num2;
  }
}

void search(int sum, int cnt, int useSign[]){
  if(cnt >= n){
    if(sum > maxSum) maxSum = sum;
    if(sum < minSum) minSum = sum;
    return;
  }

  if(cnt == 0) {
    sum = nums[cnt];
    search(sum, cnt + 1, useSign);
  }
  else{
    for(int idx = 0; idx < 4; idx++){
      if(useSign[idx] < signs[idx]){
        int newUseSign[4];
        for (int i = 0; i < 4; i++) newUseSign[i] = useSign[i];

        newUseSign[idx]++;
        search(calcNum(idx, sum, nums[cnt]), cnt + 1, newUseSign);
      }
    }
  }
}

int main(){
  cin >> n;
  
  for(int idx = 0; idx < n; idx++) cin >> nums[idx];

  for(int idx = 0; idx < 4; idx++) cin >> signs[idx];
  
  int initialUseSign[] = {0, 0, 0, 0};
  search(0, 0, initialUseSign);

  cout << maxSum << '\n' << minSum;
}