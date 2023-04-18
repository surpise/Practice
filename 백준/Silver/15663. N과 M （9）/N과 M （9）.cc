#include <iostream>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

int n, m;
array<int, 8> arr, ans, v;
set<array<int, 8>> s;

void nm(int cnt){
    if(cnt == m) s.insert(ans);
    else{
        for(int i = 0; i < n; i++){
            if(!v[i]){
                v[i] = 1;
                ans[cnt] = arr[i];
                nm(cnt + 1);
                v[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n]);
    nm(0);
    for(auto e = s.begin(); e != s.end(); e++){
        auto f = *e;
        for(int i = 0; i < m; i++) cout << f[i] << " ";
        cout << '\n';
    }
}