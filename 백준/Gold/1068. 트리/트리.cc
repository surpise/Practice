#include <iostream>

using namespace std;

int n, root, ans;
bool arr[50][50];
bool v[50];

void dfs(int node){
    v[node] = 1;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[node][i] == 1 && !v[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt == 0) ans++;
}

int main(){
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == -1) root = i;
        else{
            arr[i][x] = 1;
            arr[x][i] = 1;
        }
    }   
    cin >> x;
    if(x != root) {
        for(int i = 0; i < n; i++){
            arr[i][x] = 0;
            arr[x][i] = 0;
        } 
        dfs(root);
    }

    cout << ans;
}