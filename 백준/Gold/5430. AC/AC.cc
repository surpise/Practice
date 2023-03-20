#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int tc;
    cin >> tc;

    int n, fb;
    string p, arr;
    for(int t = 0; t < tc; t++){
        cin >> p >> n >> arr;

        deque<int> d;
        fb = 0;
        int tmp = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == ',' || arr[i] == ']') {
                if(tmp != 0) d.push_back(tmp);
                tmp = 0;
            }
            else{
                tmp *= 10;
                tmp += arr[i] - '0';
            }
        }
        for(int i = 0; i < p.size(); i++){
            if (p[i] == 'R') fb = (fb == 1) ? 0 : 1;
            else{
                if(d.size() == 0){
                    fb = -1;
                    break;
                }
                (fb) ? d.pop_back() : d.pop_front();
            }
        }
        if(fb != -1){
            cout << "[";
            if(fb){
                for(int i = d.size() - 1; i >= 0; i--){
                    cout << d[i];
                    if(i != 0) cout << ",";
                }
            }
            else if(!fb){
                for(int i = 0; i < d.size(); i++){
                    cout << d[i];
                    if(i != d.size() - 1) cout << ",";
                }
            }
            cout << "]" << '\n';
        }
        else cout << "error" << '\n';
    }
}