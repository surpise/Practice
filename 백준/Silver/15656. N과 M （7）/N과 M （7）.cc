#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[7], ans[7];

void nm(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        ans[cnt] = arr[i];
        nm(cnt + 1);
    }
}

int main(){
    cout.tie();
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(&arr[0], &arr[n]);
    nm(0);
}