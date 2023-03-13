#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<char> vec;
    string str, bomb;

    cin >> str;
    cin >> bomb;
    int str_sz = str.size(), bomb_sz = bomb.size();
    int check = 1;
    for(int i = 0; i < str_sz; i++){
        check = 1;
        vec.push_back(str[i]);
        if(vec.size() >= bomb_sz){
            for(int b = 0; b < bomb_sz; b++){
                if(vec[vec.size() - bomb_sz + b] != bomb[b]){
                    check = 0;
                    break;
                }
            }

            if(check){
                for(int k = 0; k < bomb_sz; k++) vec.pop_back();
            }
        }
    }

    if(vec.size() == 0) cout << "FRULA";
    else {
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i];
        }
    }
}