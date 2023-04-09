#include <iostream>

using namespace std;

bool arr[1000001]; 
int main(){
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        if(!arr[i]){
            for(int j = 2; i * j <= 1000000; j++) arr[i * j] = 1;
        }
    }

    int t, n, ans;
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        for(int i = 2; i <= n - i; i++){
            if(!arr[i] && !arr[n - i]) ans++; 
        }
        cout << ans << '\n';
    }
}