#include <string>
#include <vector>

#define INF 1e9
using namespace std;

int answer = INF;
bool visited[50];

bool canChange(string str1, string str2){
    int cnt = 0;
    for(int idx = 0; idx < str1.length(); idx++){
        if(str1[idx] != str2[idx]) cnt++;
    }
    
    if(cnt == 1) return true;
    else return false;
}

void search(string cur, int cnt, vector<string>words, string target){
    if(cur == target){
        if(answer > cnt) answer = cnt;
        return;
    }
    
    if(cnt == words.size()) return;
    
    for(int idx = 0; idx < words.size(); idx++){
        if(visited[idx]) continue;
        
        visited[idx] = 1;
        
        if(canChange(cur, words[idx])) search(words[idx], cnt + 1, words, target);
           
        visited[idx] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    search(begin, 0, words, target);
    
    if(answer == INF) answer = 0;
    
    return answer;
}