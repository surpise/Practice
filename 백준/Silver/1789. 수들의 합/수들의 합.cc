#include <iostream>
using namespace std;

int main(){
    unsigned int S, N = 1, ans = 0;
    cin >> S;

    while(S >= N){
        S -= N;
        ans++;
        N++;
    }

    cout << ans;
}