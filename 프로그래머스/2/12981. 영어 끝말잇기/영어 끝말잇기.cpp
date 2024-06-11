#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> strSet;
    char lastAlpha = words[0][0];
    for(int idx = 0; idx < words.size(); idx++){
        if(words[idx][0] != lastAlpha || strSet.find(words[idx]) != strSet.end()){
            return {idx % n + 1, idx / n + 1};
        }
        else {
            lastAlpha = words[idx][words[idx].size() - 1];
            strSet.insert(words[idx]);
        }
    }
    
    return {0, 0};
}