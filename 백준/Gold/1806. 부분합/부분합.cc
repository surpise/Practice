#include <iostream>

using namespace std;

int main(){
    int arr[100001] = {0, };
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int a = 0, b = 1, ps = 0, ans = 100001;
    while(a < b){
        ps = arr[b] - arr[a];
        if(ps >= s){
            if(b - a < ans) ans = b - a;
            a++;
        }
        else b++;
        if(b > n) break;
    }
    if(ans == 100001) ans = 0;
    cout << ans;
}