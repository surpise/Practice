#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    char arr[5] = {'a', 'e', 'i', 'o', 'u'};
    string answer = "";
    for(int i = 0; i < my_string.size(); i++){
        for(int j = 0; j < 5; j++){
            if(my_string[i] == arr[j]) break;
            else if(j == 4) answer += my_string[i];
        }
    }
    return answer;
}