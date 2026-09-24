class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans1 = -1;
        int ans2 = -1;
        int freq1 = 0;
        int freq2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans1) {
                freq1++;
            } else if (nums[i] == ans2) {
                freq2++;
            } else if (freq1 == 0) {
                ans1 = nums[i];
                freq1 = 1;
            } else if (freq2 == 0) {
                ans2 = nums[i];
                freq2 = 1;
            } else {
                freq1--;
                freq2--;
            }
        }

        freq1 = freq2 = 0;
        for (int x : nums) {
            if (ans1 == x)
                freq1++;
            else if (ans2 == x)
                freq2++;
        }
        vector<int> res;
        if (freq1 > n / 3) res.push_back(ans1);
        if (freq2 > n / 3) res.push_back(ans2);

        return res;
    }
};
