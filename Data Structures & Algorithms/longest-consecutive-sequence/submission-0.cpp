class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        unordered_set<int>seen;
        
        for(int x : nums){
            seen.insert(x);
        }

        for(int i=0;i<n;i++){
            if(!seen.count(nums[i] - 1)){
               int curr = nums[i];
               int len = 1;
               
               while(seen.count(curr + 1)){
                curr++;
                len++;
               }
             maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};
