class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;
        const auto sz = nums.size();
        for (auto i = 0u; i < sz; ++i) {
            if (nums[i] != val) {
                nums[ret++] = nums[i];
            }
        }
        return ret;
    }
};
