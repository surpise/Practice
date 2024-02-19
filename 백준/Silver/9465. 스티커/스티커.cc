#include <iostream>

using namespace std;

void sticker(int length){
  int stickers[2][100000];
  for(int line = 0; line < 2; line++){
    for(int idx = 0; idx < length; idx++) {
      cin >> stickers[line][idx];
    }
  }

  int dp[2][100000] ={
    {stickers[0][0], stickers[1][0] + stickers[0][1]},
    {stickers[1][0], stickers[0][0] + stickers[1][1]}
  };

  for(int idx = 2; idx < length; idx++){
    dp[0][idx] = stickers[0][idx] + max(dp[1][idx - 1], dp[1][idx - 2]);
    dp[1][idx] = stickers[1][idx] + max(dp[0][idx - 1], dp[0][idx - 2]);
  }

  cout << max(dp[0][length - 1], dp[1][length - 1]) << '\n';
}

int main(){
  int t, n;
  cin >> t;

  for(int testCase = 0; testCase < t; testCase++){
    cin >> n;
    sticker(n);
  }
}