class Solution {
   public:
    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string ans;
        vector<int> size;
        for (string& s : strs) {
            size.push_back(s.size());
        }
        for (int s : size) {
            ans.append(to_string(s));
            ans.push_back(',');
        }
        ans.push_back('#');
        for (string& s : strs) {
            ans.append(s);
        }
        return ans;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }
        vector<int> size;
        vector<string> ans;
        int i = 0;
        while (s[i] != '#') {
            int j = i;
            while (s[j] != ',') {
                j++;
            }
            size.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;
        for (int sz : size) {
            ans.push_back(s.substr(i, sz));
            i += sz;
        }
        return ans;
    }
};
