#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmpTotalPlays(pair<string ,int> a, pair<string, int> b){
    return a.second > b.second;
}

bool cmpSongsPlays(pair<int ,int> a, pair<int, int> b){
    if(a.second > b.second) return true;
    else if(a.second == b.second){
        return a.first < b.first;
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> totalPlays;
    map<string, vector<pair<int, int>>> songs;
    
    for(int idx = 0; idx < genres.size(); idx++){
        auto item = totalPlays.find(genres[idx]);
        if(item != totalPlays.end()){
            item->second += plays[idx];
            auto songsList = songs.find(genres[idx]);
            songsList->second.push_back({idx, plays[idx]});
        }
        else{
            totalPlays.insert({genres[idx], plays[idx]});
            songs[genres[idx]].push_back({idx, plays[idx]});
        }
    }
    
    vector<pair<string, int>> vec(totalPlays.begin(), totalPlays.end());
    sort(vec.begin(), vec.end(), cmpTotalPlays);
    
    for(int idx = 0; idx < vec.size(); idx++){
        auto songVec = songs.find(vec[idx].first);
        sort(songVec->second.begin(), songVec->second.end(), cmpSongsPlays);
        
        answer.push_back(songVec->second[0].first);
        if(songVec->second.size() > 1) answer.push_back(songVec->second[1].first);
    }
    
    return answer;
}