class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ele_to_opt_out = 0;
        int nums_size = nums.size();
        vector<int>ans;

        while(ele_to_opt_out < nums_size) {
            int ele_prod = 1;
            for(int i = 0; i < nums_size; i++) {
                if(i != ele_to_opt_out) {
                    ele_prod *= nums[i];
                }
            }
            ans.push_back(ele_prod);
            ele_to_opt_out++;
            ele_prod = 1;
        }
        return ans;
    }
};
