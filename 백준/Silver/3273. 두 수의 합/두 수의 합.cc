#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];
int main(){
    int n, x, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    sort(&arr[0], &arr[n]);
    int i = 0, j = n - 1;
    while(i < j){
        if(arr[i] + arr[j] < x) i++;
        else{
            if(arr[i] + arr[j] == x) ans++;
            j--;
        }
    }
    cout << ans;
}