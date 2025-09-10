class Solution {
public:
    bool langverify(int user, int usertwo, std::vector<std::vector<int>>& languages) {
        std::vector<int>& aux = languages[user];
        std::vector<int>& auxtwo = languages[usertwo];

        for (int lang1 : aux) {
            for (int lang2 : auxtwo) {
                if (lang1 == lang2) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        int min_teachings = INT_MAX;
        
        std::unordered_set<int> people_to_teach;
        for (const auto& friendship : friendships) {
            int user1 = friendship[0] - 1;
            int user2 = friendship[1] - 1;
            
            if (!langverify(user1, user2, languages)) {
                people_to_teach.insert(user1);
                people_to_teach.insert(user2);
            }
        }

        if (people_to_teach.empty()) {
            return 0;
        }

        for (int lang_id = 1; lang_id <= n; ++lang_id) {
            int current_teachings = 0;
            
            for (int person : people_to_teach) {
                if (std::find(languages[person].begin(), languages[person].end(), lang_id) == languages[person].end()) {
                    current_teachings++;
                }
            }
            min_teachings = std::min(min_teachings, current_teachings);
        }
        
        return min_teachings;
    }
};
