#include <iostream>
#include <queue>
#include <array>
using namespace std;

int n, ans = 10000;
int arr[100][100], dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
bool v[100][100];
queue<array<int, 3>> q;

void landck(int lr, int lc, int t){
    v[lr][lc] = 1;
    arr[lr][lc] = t;
    for(int i = 0; i < 4; i++){
        if(lr + dr[i] < 0 || lr + dr[i] >= n || lc + dc[i] < 0 || lc + dc[i] >= n) {
            continue;
        }
        if(!v[lr + dr[i]][lc + dc[i]] && arr[lr + dr[i]][lc + dc[i]] == 1) {
            landck(lr + dr[i], lc + dc[i], t);
        }
    }
}

void mkbridge(int x){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == x) {
                q.push({i, j, 0});
                v[i][j] = 1;
            }
        }
    }
    
    int _r, _c, l;
    while(!q.empty()){
        _r = q.front()[0], _c = q.front()[1], l = q.front()[2];
        q.pop();
        for(int i = 0; i < 4; i++){
            int tr = _r + dr[i], tc = _c + dc[i];
            if(tr < 0 || tr >= n || tc < 0 || tc >= n) continue;
            if(!v[tr][tc]){
                if(arr[tr][tc] != 0 && arr[tr][tc] != x){
                    while(!q.empty()) q.pop();
                    if(l < ans) ans = l;
                    return;
                }
                if(!arr[tr][tc]){
                    v[tr][tc] = 1;
                    q.push({tr, tc, l + 1});
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)  cin >> arr[i][j];
    }

    int ad = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1 && !v[i][j]){
                landck(i, j, ad);
                ad++;
            }
        }
    }

    for(int i = 1; i < ad; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++) v[j][k] = 0;
        }
        mkbridge(i);
    }
    cout << ans;
}