class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0;
        while (l < n) {
            if (nums[l] == val) {
                nums[l] = nums[n - 1];
                n--;
            } else {
                l++;
            }
        }
        return n;
    }
};