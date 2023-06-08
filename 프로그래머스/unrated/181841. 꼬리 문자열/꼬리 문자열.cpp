#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    int t, c;
    for(int i = 0; i < str_list.size(); i++){
        c = 1;
        if(str_list[i].size() >= ex.size()){
            for(int j = 0; j <= str_list[i].size() - ex.size(); j++){
                t = 1;
                if(str_list[i][j] == ex[0]){
                    for(int k = 1; k < ex.size(); k++){
                        if(str_list[i][j + k] != ex[k]) t = 0;
                    }
                    if(t) c = 0;
                }
            }
        }

        if(c) answer += str_list[i];
    }
    return answer;
}