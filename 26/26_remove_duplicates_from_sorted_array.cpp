class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret      = 0;
        const int sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (nums[i] != nums[ret]) {
                nums[++ret] = nums[i];
            }
        }
        return ret + 1;
    }
};
