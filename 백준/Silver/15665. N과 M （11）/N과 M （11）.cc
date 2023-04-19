#include <iostream>
#include <algorithm>
#include <array>
#include <set>
using namespace std;

int n, m;
array<int, 7> arr, ans;
set<array<int, 7>> s;

void nm(int cnt){
    if(cnt == m){
        s.insert(ans);
        return;
    }
    for(int i = 0; i < n; i++){
        ans[cnt] = arr[i];
        nm(cnt + 1);
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