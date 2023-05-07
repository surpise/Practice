#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long arr[5000];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n]);

    int m, r, ansl, ansm, ansr;
    long long t, sum = 3000000003;
    for(int l = 0; l < n - 2; l++){
        m = l + 1;
        r = n - 1;
        while(m < r){
            t = arr[l] + arr[m] + arr[r];
            if(abs(t) <= sum){
                sum = abs(t);
                ansl = arr[l];
                ansm = arr[m];
                ansr = arr[r];
            }
            if(t < 0) m++;
            else r--;
        }
    }

    cout << ansl << " " << ansm << " " << ansr;
}