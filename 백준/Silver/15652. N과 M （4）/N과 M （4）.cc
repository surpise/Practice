#include <iostream>

using namespace std;

int n, m;
int ans[8];
void nm(int cnt, int k){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    else{
        for(int i = 1; i <= n; i++){
            if(i >= k){
                ans[cnt] = i;
                nm(cnt + 1, i);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    nm(0, 0);
}