class Solution {
   private:
    void merge_sort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        int l = low;
        int r = mid + 1;
        vector<int> temp;

        while (l <= mid && r <= high) {
            if (nums[l] < nums[r]) {
                temp.push_back(nums[l++]);
            } else {
                temp.push_back(nums[r++]);
            }
        }

        while (l <= mid) {
            temp.push_back(nums[l++]);
        }
        while (r <= high) {
            temp.push_back(nums[r++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};
