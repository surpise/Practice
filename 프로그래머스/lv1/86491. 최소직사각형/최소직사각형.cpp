#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wmax = 0, hmax = 0, w, h;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            w = sizes[i][1];
            h = sizes[i][0];
        }
        else{
            w = sizes[i][0];
            h = sizes[i][1];
        }
        if(w > wmax) wmax = w;
        if(h > hmax) hmax = h;
    }
    int answer = wmax * hmax;
    return answer;
}