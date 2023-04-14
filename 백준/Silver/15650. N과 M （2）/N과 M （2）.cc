#include <iostream>

using namespace std;

int n, m;
bool visited[9];
int ans[8]; 

void nm(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << endl;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(!visited[i] && i > ans[cnt - 1]){
                visited[i] = 1;
                ans[cnt] = i;
                nm(cnt + 1);
            }
            visited[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    nm(0);
}