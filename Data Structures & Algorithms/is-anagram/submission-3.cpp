class Solution {
   public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for (char x : s) {
            arr[x - 'a']++;
        }
        for (char x : t) {
            arr[x - 'a']--;
        }

        for (int x : arr) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};
