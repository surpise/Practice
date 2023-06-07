#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int last = num_list[num_list.size() - 1], plast = num_list[num_list.size() - 2];
    if(last > plast) num_list.push_back(last - plast);
    else num_list.push_back(last * 2);
    return num_list;
}