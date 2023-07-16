#include <iostream>

using namespace std;

int main(){
    bool eat = true;
    int ans = 0, m;
    for(int i = 0; i < 10; i++){
        cin >> m;
        if(eat){
            if(ans + m <= 100){
                ans += m;
            }
            else{
                if(100 - ans >= ans + m - 100){
                    ans += m;
                }
                else{
                    eat = false;
                }
            }
        }
    }
    cout << ans;
}