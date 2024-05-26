#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    int dp[2001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int idx = 4; idx <= n; idx++){
        dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 1234567;
    }
    
    answer = dp[n];
    return answer;
}
