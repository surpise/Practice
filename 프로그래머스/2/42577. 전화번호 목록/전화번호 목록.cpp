#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> m;
    
    for(int idx = 0; idx < phone_book.size(); idx++){
        m.insert({phone_book[idx], idx});
    }    
    
    for(int idx = 0; idx < phone_book.size(); idx++){
        for(int j = 0; j < phone_book[idx].size(); j++){
            if(m.find(phone_book[idx].substr(0, j)) != m.end()) return false;
        }
    }
    
    return true;
}