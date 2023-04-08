#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    vector<string> v = {"zer", "one", "two", "thr", "fou", "fiv", "six", "sev", "eig", "nin"};
    int answer = 0, cnt = 0;
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] - '0' < 10){
            answer *= 10;
            answer += s[i] - '0';
            cnt = 0;
            tmp = "";
        }
        else{
            cnt ++;
            tmp += s[i];
            if(cnt == 3){
                auto e = find(v.begin(), v.end(), tmp);
                int idx = e - v.begin();
                if(idx == 0 || idx == 4 || idx == 5 || idx == 9) i++;
                else if(idx == 3 || idx == 7 || idx == 8) i += 2;
                answer *= 10;
                answer += idx;
                cnt = 0; 
                tmp = "";
            }
        }
    }
    return answer;
}