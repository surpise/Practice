#include <iostream>

using namespace std;

int main(){
    int n;
    string x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(x[x.size() - 1] % 2 == 0) cout << "even\n";
        else cout << "odd\n"; 
    }
}