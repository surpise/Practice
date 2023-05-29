#include <iostream>

using namespace std;

int main(){
    int ans = 0;
    string str;

    for(int i = 0; i < 8; i++){
        cin >> str;
        for(int j = 0; j < 8; j++){
            if(i % 2 == 0 && j % 2 == 0 && str[j] == 'F') ans++;
            if(i % 2 == 1 && j % 2 == 1 && str[j] == 'F') ans++;
        }
    }
    cout << ans;
}