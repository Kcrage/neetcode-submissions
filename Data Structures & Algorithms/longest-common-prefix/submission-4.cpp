class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        if (strs.size() == 1){
            return strs[0];
        }
        int minS = min(strs[0].length(), strs[n - 1].length());
        string ans = ""; 

        for (int i = 0; i < minS; i++) {
            if (strs[0][i] != strs[n - 1][i]) {
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};