#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    set<string> d = {"ChongChong"};
    string a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(d.find(a) != d.end()) d.insert(b);
        else if(d.find(b) != d.end()) d.insert(a);
    }
    cout << d.size();
}