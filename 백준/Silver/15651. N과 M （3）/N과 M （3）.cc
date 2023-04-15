#include <iostream>

using namespace std;
int n, m;

int ans[7];
void nm(int cnt){
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    else{
        for(int i = 1; i <= n; i++){
            ans[cnt] = i;
            nm(cnt + 1);
        }
    }
}

int main(){
    cout.tie();
    ios::sync_with_stdio(false);
    cin >> n >> m;
    nm(0);
}