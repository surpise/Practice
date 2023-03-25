#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long long min = 1, max = k, mid, tmp, ans;
    while(max >= min){
        mid = (min + max) / 2;
        tmp = 0;
        for(int i = 1; i <= n; i++){
            if((mid / i) > n) tmp += n;
            else tmp += mid / i;
        }
        if(tmp < k) min = mid + 1;
        else {
            ans = mid;
            max = mid - 1;        
        }
    }
    cout << ans;
}