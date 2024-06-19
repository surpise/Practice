#include <iostream>

using namespace std;

int n, m;
int arr1[1000000], arr2[1000000];

int main(){
    cin >> n >> m;
    for(int idx = 0; idx < n; idx++) cin >> arr1[idx];
    for(int idx = 0; idx < m; idx++) cin >> arr2[idx];

    int idx1 = 0, idx2 = 0;

    while(1){
        if(idx1 >= n && idx2 >= m) break;

        if(idx1 >= n) cout << arr2[idx2++] << " ";
        else if(idx2 >= m) cout << arr1[idx1++] << " ";
        else if(arr1[idx1] <= arr2[idx2]) cout << arr1[idx1++] << " ";
        else if(arr2[idx2] < arr1[idx1]) cout << arr2[idx2++] << " ";
    }
}