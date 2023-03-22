#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    vector<string> v;
    string tmp;
    sort(spell.begin(), spell.end());
    for(int i = 0; i < dic.size(); i++){
        if(dic[i].size() == spell.size()){
            for(int j = 0; j < dic[i].size(); j++) {
                tmp = dic[i][j];
                v.push_back(tmp);
            }
            sort(v.begin(), v.end());
            int cnt = 0;
            for(int j = 0; j < v.size(); j++){
                if(spell[j] == v[j]) cnt++;
            }
            if(cnt == v.size()) answer = 1;
        }
        v.clear();
    }
    return answer;
}