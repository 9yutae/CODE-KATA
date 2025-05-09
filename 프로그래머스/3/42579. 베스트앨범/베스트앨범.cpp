#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Music {
    int index;
    int PlayNum;
    string Genre;
};

bool compare(const Music& lhs, const Music& rhs) {
    if (lhs.PlayNum == rhs.PlayNum) return lhs.index < rhs.index;
    return lhs.PlayNum > rhs.PlayNum;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, vector<Music>> Chart;
    map<string, int> PlayNumsbyGenre;
    int n = genres.size();
    for (int i = 0 ; i < n ; i++) {
        string genre = genres[i];
        int play = plays[i];
        
        PlayNumsbyGenre[genre] += play;
        Chart[genre].push_back({i, play, genre});
    }
    
    for (auto& genre : Chart) {
        sort(genre.second.begin(), genre.second.end(), compare);
    }
    
    vector<pair<string, int>> vec(PlayNumsbyGenre.begin(), PlayNumsbyGenre.end());
    sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) {
        return lhs.second > rhs.second;
    });
    
    vector<string> GenreRank;
    for (const auto& w : vec) {
        GenreRank.push_back(w.first);
    }
    
    vector<int> answer;
    for (const auto& genre : GenreRank) {
        answer.push_back(Chart[genre][0].index);
        if (Chart[genre].size() != 1) answer.push_back(Chart[genre][1].index);
    }
    
    return answer;
}