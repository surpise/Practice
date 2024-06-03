#include <iostream>

using namespace std;

long long dp[100001][4];

void calc(){
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

    for(int idx = 4; idx <= 100000; idx++){
        dp[idx][1] = (dp[idx - 1][2] + dp[idx - 1][3]) % 1000000009;
        dp[idx][2] = (dp[idx - 2][1] + dp[idx - 2][3]) % 1000000009;
        dp[idx][3] = (dp[idx - 3][1] + dp[idx - 3][2]) % 1000000009;
    }
}

int main(){
    calc();

    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++){
        int n;
        cin >> n;

        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
    }
}