#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9], ans[9];

void nm(int cnt){
    if(cnt > m){
        for(int i = 1; i <= m; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(arr[i] >= ans[cnt - 1]){
            ans[cnt] = arr[i];
            nm(cnt + 1);
        }
    }
}

int main(){
    cin >> n >> m;    
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n + 1]);
    nm(1);
}