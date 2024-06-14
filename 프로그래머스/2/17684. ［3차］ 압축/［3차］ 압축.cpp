#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> dic;
    for(int i =  0; i < 26; i++){
        dic.insert({string(1, 'A' + i), i + 1});
    }
    
    int cnt = 27;
    for(int idx = 0; idx < msg.size(); idx++){
        string tmp = ""; 
        
        while(1){
            if(idx >= msg.size()) {
                answer.push_back(dic.find(tmp)->second);
                break;
            }
            tmp += msg[idx];
            
            if(dic.find(tmp) != dic.end()) idx++;
            else{
                dic.insert({tmp, cnt++});
                tmp = tmp.substr(0, tmp.size() - 1);
                answer.push_back(dic.find(tmp)->second);
                idx--;
                break;
            }
        }
    }
    
    return answer;
}