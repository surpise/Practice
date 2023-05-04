#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, sum = 2000000000, a, b;
    int arr[100000];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(&arr[0], &arr[n]);

    int i = 0, j = n - 1, t;
    while(i < j){
        t = arr[i] + arr[j] - 0;
        if(abs(t) <= sum){
            sum = abs(t);
            a = arr[i];
            b = arr[j];
        } 
        if(t > 0)j--;
        else i++;
    }
    cout << a << " " << b;
}