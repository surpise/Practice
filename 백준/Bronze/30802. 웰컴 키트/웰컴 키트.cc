#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int size[6];
    for(int idx = 0; idx < 6; idx++) cin >> size[idx];

    int t, p;
    cin >> t >> p;

    int ansT = 0;
    for(int idx = 0; idx < 6; idx++){
        ansT += size[idx] / t;
        if(size[idx] % t) ansT++;
    }

    cout << ansT << '\n' << n / p << " " << n % p;
}