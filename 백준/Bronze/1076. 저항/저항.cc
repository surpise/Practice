#include <iostream>
#include <map>

using namespace std;

int main(){
    string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    string str;
    long long ans = 0;
    for(int i = 0; i < 3; i++){
        cin >> str;
        if(i < 2){
            for(int j = 0; j < 10; j++){
                if(str == color[j]){
                    ans *= 10;
                    ans += j;
                }
            }
        }
        else{
            for(int j = 0; j < 10; j++){
                if(str == color[j]){
                    for(int t = 0; t < j; t++) ans *= 10;
                }
            }
        }
    }
    cout << ans;
}