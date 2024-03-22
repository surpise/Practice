#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int arr[101][101] = {{0, }, {0, }};
    
    for(int idx = 0; idx < puddles.size(); idx++){
        arr[puddles[idx][0]][puddles[idx][1]] = -1;
    }
    
    arr[1][1] = 1;
    for(int r = 1; r <= m; r++){
        for(int c = 1; c <= n; c++){
            if(arr[r][c] == -1) continue;
            
            if(r - 1 > 0 && arr[r - 1][c] != -1) arr[r][c] += arr[r - 1][c];
            arr[r][c] %=  1000000007;
            
            if(c - 1 > 0 && arr[r][c - 1] != -1) arr[r][c] += arr[r][c - 1];
            arr[r][c] %=  1000000007;
        }
    }
    
    return arr[m][n];
}