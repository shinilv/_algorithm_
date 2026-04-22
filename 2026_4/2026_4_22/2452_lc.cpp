class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s : queries) {
            for (auto& t : dictionary) {
                int cnt = 0;
                if (s.size() == t.size()) {
                    for (int i = 0; i < s.size(); i++) {
                        if (s[i] != t[i]) cnt += 1;
                    }
                    if (cnt <= 2) {
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};