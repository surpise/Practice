#include <iostream>
#include <algorithm>
#include <array>
#include <set>

using namespace std;

int n, m;
array<int, 9> arr, ans, v;
set<array<int, 9>> s;

void nm(int cnt){
    if(cnt > m) s.insert(ans);
    else{
        for(int i = 1; i <= n; i++){
            if(!v[i] && ans[cnt - 1] <= arr[i]){
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
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n + 1]);
    nm(1);
    for(auto e = s.begin(); e != s.end(); e++){
        auto f = *e;
        for(int i = 1; i <= m; i++) cout << f[i] << " ";
        cout << '\n';
    }
}