#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cout << n << " is ";
    if(n % 2 == 0) cout << "even";
    else cout << "odd";
    return 0;
}