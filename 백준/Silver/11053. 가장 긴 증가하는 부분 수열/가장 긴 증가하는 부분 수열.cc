#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], ans[1001];
int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> arr[i];
    
    int t;
    for(int i = 1; i <= n; i++){
        t = 0;
        for(int j = 0; j <= i; j++){
           if(arr[j] < arr[i]) t = max(ans[j], t);
        }
        ans[i] = t + 1;
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i] > res) res = ans[i];
    }
    cout << res;
}