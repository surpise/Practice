#include <iostream>

using namespace std;

int n;
void printA(){
    for(int i = 0; i < n; i++) cout << "@";
}
void printBlank3(){
    for(int i = 0; i < n; i++) cout << "   ";
}
void printBlank2(){
    for(int i = 0; i < n; i++) cout << "  ";
}
int main(){
    cin >> n;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < n; j++){
            printA();
            if(i == 0 || i == 4) printBlank3();
            else if(i == 1 || i == 3) printBlank2();
            else printA();
            printA();
            cout << '\n';
        }
    }
}