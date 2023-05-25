#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[100000];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    sort(&arr[0], &arr[n]);

    int l = 0, r = 0, ans = 2000000001;
    while(1){
        if(arr[r] - arr[l] >= m){
            if(arr[r] - arr[l] < ans){
                ans = arr[r] - arr[l];
            }
            else{
                l++;
            }
        }
        else{
            r++;
        }
        if(r > n || l > n) break;
    }
    cout << ans;
}