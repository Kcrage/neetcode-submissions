class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum = 0;
        int res = 0;
        unordered_map<int, int> psum;
        psum[0] = 1;

        for (int num : nums) {
            currsum += num;
            int need = currsum - k;
            res += psum[need];
            psum[currsum]++;
        }

        return res;
    }
};