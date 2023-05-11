#include <iostream>

using namespace std;

int n, ans;
int arr[16][16];

void dfs(pair<int, int> r, int state){
    if(r.first == n - 1 && r.second == n - 1) {
        ans++;
        return;
    }
    if(state != 0 && r.first + 1 < n){
        if(arr[r.first + 1][r.second] != 1){
            dfs({r.first + 1, r.second}, 1);
        }
    }
    if(state != 1 && r.second + 1 < n){
        if(arr[r.first][r.second + 1] != 1){
            dfs({r.first, r.second + 1}, 0);
        }
    }
    if(r.first + 1 < n && r.second + 1 < n){
        if(arr[r.first + 1][r.second] != 1 && arr[r.first][r.second + 1] != 1 && arr[r.first + 1][r.second + 1] != 1){
            dfs({r.first + 1, r.second + 1}, 2);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }
    dfs({0, 1}, 0);
    cout << ans;
}