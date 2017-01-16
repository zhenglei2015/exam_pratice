class Solution {
    pair<int, int> pos[3000];
    static bool compare(pair<int, int> a, pair<int, int> b) {
        if(a.first != b. first)
            return a.first < b.first;
        else
            return a.second > b.second;
    }

public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        for(int i = 0; i < 2000; i++) {
            pos[i].first = -1;
            pos[i].second = -1;
        }
        for(int i = 0; i < people.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < people.size(); j++) {
                if(pos[j].first == -1) {
                    cnt++;
                }
                if(cnt == people[i].second + 1) {
                    pos[j].first = people[i].first;
                    pos[j].second = people[i].second;
                    break;
                }
            }  
        }
        vector<pair<int, int>> temp;
        for(int i = 0; i < people.size(); i++) {
            temp.push_back(pair<int, int>(pos[i].first, pos[i].second));
        }
        return temp;
    }
};
