#include <iostream>

using namespace std;

int main(){
    int arr[100000];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] + arr[i - 1] > arr[i]) arr[i] += arr[i - 1];
        if(arr[i] > ans) ans = arr[i];
    }

    cout << ans;
}