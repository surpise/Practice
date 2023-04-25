#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m1;
    map<int, string> m2;
    string tmp;
    for(int i = 0; i < players.size(); i++) {
        m1.insert({players[i], i});
        m2.insert({i, players[i]});
    }
    for(int i = 0; i < callings.size(); i++){
        auto a1 = m1.find(callings[i]);
        auto a2 = m2.find(a1->second);
        auto b2 = m2.find(a1->second - 1);
        auto b1 = m1.find(b2->second);
        a1->second--;
        tmp = a2->second;
        a2->second = b2->second;
        b2->second = tmp;
        b1->second++;
    }
    for(auto e = m2.begin(); e != m2.end(); e++) answer.push_back(e->second);
    return answer;
}