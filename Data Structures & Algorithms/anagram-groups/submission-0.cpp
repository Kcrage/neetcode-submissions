class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mm;
        for (const string&s : strs) {
            int freq[26] = {0};
            for (char c : s) {
                freq[c - 'a']++;
            }
          string key = to_string(freq[0]);
          for(int i=0;i<26;i++){
            key += to_string(freq[i]);
            key += '#';
          }
          mm[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(const auto& pair : mm){
          ans.push_back(pair.second);
        }
        return ans;
    }
};
          
