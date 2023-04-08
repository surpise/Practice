#include <iostream>

using namespace std;
 
int main(){
    int a1, a2, b1, b2, ans1, ans2, t;
    cin >> a1 >> a2 >> b1 >> b2;
    ans1 = (a1 * b2) + (a2 * b1);
    ans2 = a2 * b2;

    int big = (ans1 > ans2) ? ans1 : ans2;
    int small = (ans1 + ans2) - big;
    while(big % small != 0){
        t = big % small;
        big = small;
        small = t;
    }
    cout << ans1 / small << " " << ans2 / small;
}