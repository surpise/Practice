#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int N, M, b;
    bool bt[10] = {0, };

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> b;
        bt[b] = true;
    }

    int t1, t2, pn = N, mn = N, fp, fn;
    string plus, minus;
    t1 = abs(N - 100);
    if(M == 10) cout << t1;
    else{
        while(1){
            fp = 1;
            fn = 1;
            plus = to_string(pn);
            minus = to_string(mn);
            for(int i = 0; i < plus.length(); i++){
                if(bt[plus[i] - '0']) fp = 0;
            }
            for(int i = 0; i < minus.length(); i++){
                if(bt[minus[i] - '0']) fn = 0;
            }

            if(fp && fn){
                t2 = min(pn - N + plus.length(), N - mn + minus.length());
                break;
            }
            else if(fp){
                t2 = pn - N + plus.length();
                break;
            }
            else if(fn){
                t2 =  N - mn + minus.length();
                break;
            }
            pn++;
            mn--;
        }

        cout << min(t1, t2);
    }
}