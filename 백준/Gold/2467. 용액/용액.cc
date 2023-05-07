#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, r = n - 1, ansl, ansr;
    long long t, diff = 2000000002;
    while(l < r){
        t = arr[l] + arr[r] - 0;
        if(abs(t) <= diff){
            diff = abs(t);
            ansl = arr[l];
            ansr = arr[r];
        }
        if(t > 0) r--;
        else l++;
    }
    cout << ansl << " " << ansr;
}