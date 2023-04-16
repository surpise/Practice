#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[9];
bool v[9];

void nm(int cnt){
    if(cnt > m){
        for(int i = 1; i <= m; i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!v[i] && ans[cnt - 1] < arr[i - 1]){
            v[i] = 1;
            ans[cnt] = arr[i - 1];
            nm(cnt + 1);
            v[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n]);
    nm(1);
}