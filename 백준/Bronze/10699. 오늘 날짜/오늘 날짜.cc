#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int main(){
    auto now =  chrono::system_clock::now();
    auto day = chrono::system_clock::to_time_t(now);
    cout << put_time(localtime(&day), "%Y-%m-%d");
}