#include <iostream>

using namespace std;

int checkPaildrome(string str, int lIdx, int rIdx, bool flag){
    while(lIdx < rIdx){
        if(str[lIdx] == str[rIdx]){
            lIdx++;
            rIdx--;
        }
        else{
            if(flag){
                int delLeftRes = checkPaildrome(str, lIdx + 1, rIdx, 0);
                int delRightRes = checkPaildrome(str, lIdx, rIdx - 1, 0);

                if(!delLeftRes || !delRightRes) return 1;
                else return 2;
            }
            else return 2;
        }
    }

   return 0;
}

int main(){
    int t;
    cin >> t;

    for(int tc = 0; tc < t; tc++){
        string str;
        cin >> str;
        cout << checkPaildrome(str, 0, str.size() - 1, 1) << '\n';
    }
}