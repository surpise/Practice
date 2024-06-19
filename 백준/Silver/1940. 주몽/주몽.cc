#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[15000];

int main(){
    cin >> n >> m;
    for(int idx = 0; idx < n; idx++) cin >> arr[idx];

    sort(arr, arr + n);

    int lIdx = 0; int rIdx = n - 1;
    int ans = 0;
    while(lIdx < rIdx){
        int sum = arr[lIdx] + arr[rIdx];
        if(sum == m){
            ans++;
            lIdx++;
            rIdx--;
        }
        else if(sum < m) lIdx++;
        else rIdx--;
    }

    cout << ans;
}