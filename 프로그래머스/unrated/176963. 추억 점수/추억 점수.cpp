#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    int sum;
    for(int i = 0; i < name.size(); i++) m.insert({name[i], yearning[i]});
    for(int i = 0; i < photo.size(); i++){
        sum = 0;
        for(int j = 0; j < photo[i].size(); j++){
            auto t = m.find(photo[i][j]);
            if(t != m.end()) sum += t -> second; 
        }
        answer.push_back(sum);
    }
    return answer;
}