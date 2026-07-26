class Solution {
public:
    int quickSelect(vector<int> &nums, int left, int right, int targetIndex) {
        int pivot = nums[right];
        int p = left;

        for(int i = left; i < right; ++i) {
            if(nums[i] <= pivot) {
                swap(nums[p], nums[i]);
                p++;
            }
        }
        swap(nums[p], nums[right]);

        if(p > targetIndex) {
            return quickSelect(nums, left, p-1, targetIndex);
        } else if(p < targetIndex) {
            return quickSelect(nums, p+1, right, targetIndex);
        } else {
            return nums[p];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int targetIndex = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, targetIndex);
    }
};
