#include <iostream>

using namespace std;

int arr[100001];
int main(){
    int n, k, t = 0, ans;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
        if(i >= k) {
            if(i == k) ans = arr[i] - arr[t];
            else if(ans < arr[i] - arr[t]) ans = arr[i] - arr[t];
            t++;
        }
    }

    cout << ans;
}