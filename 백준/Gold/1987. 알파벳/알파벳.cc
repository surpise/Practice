#include <iostream>

using namespace std;

int r, c, ans;
char arr[20][20];
bool vAlpha[26];

void dfs(int _r, int _c, int cnt){
    if(!vAlpha[arr[_r][_c] - 'A']){
        vAlpha[arr[_r][_c] - 'A'] = 1;
        if(_r - 1 >= 0) dfs(_r - 1, _c, cnt + 1);
        if(_c - 1 >= 0) dfs(_r, _c - 1 , cnt + 1);
        if(_r + 1 < r) dfs(_r + 1, _c, cnt + 1);
        if(_c + 1 < c) dfs(_r, _c + 1, cnt + 1);
        vAlpha[arr[_r][_c] - 'A'] = 0;
    }
    else{
        if(cnt > ans) ans = cnt;
    }
}

int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cin >> arr[i][j];
    }
    dfs(0, 0, 0);
    if(ans == 0){
        ans = 1;
    }
    cout << ans;
}