#include <iostream>

using namespace std;

int n, m, ans;
int arr[501][501];
int dp[501][501];
int d[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};

int dfs(int r, int c){
    if(r == n && m == c)return 1;
    if(dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 0;
    int tr, tc;
    for(int i = 0; i < 4; i++){
        tr = r + d[0][i];
        tc = c + d[1][i];
        if(tr < 1 || tr > n || tc < 1 || tc > m) continue;
        if(arr[tr][tc] < arr[r][c]){
            dp[r][c] = dp[r][c] + dfs(tr, tc);
        }
    }
    return dp[r][c];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(1, 1);
}