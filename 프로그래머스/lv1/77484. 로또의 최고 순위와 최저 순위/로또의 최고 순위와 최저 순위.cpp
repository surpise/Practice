#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 7, z = 0;
    for(int i = 0; i < 6; i++){
        if(lottos[i] == 0) z++;
        else if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) cnt--;
    }
    if(cnt - z >= 6) answer.push_back(6);
    else answer.push_back(cnt - z);
    if(cnt >= 6) answer.push_back(6);
    else answer.push_back(cnt);
    return answer;
}