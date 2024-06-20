#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;

    cin >> n;

    int left = 0, right = 0;
    int lb = 1, rb = 1;
    int ans = 0;

    while(1){
        
        if(lb > n + 1 || rb > n + 1) break;

        int tmp = right - left;

        if(tmp < n){
            right += rb;
            rb++;
        }
        else{
            if(tmp == n) ans++;
            
            left += lb;
            lb++;
        }
    }

    cout << ans;
}