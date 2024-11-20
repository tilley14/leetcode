class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) != val) {
                if (ret != i) {
                    auto tmp = nums.at(ret);
                    nums[ret] = nums.at(i);
                    nums[i] = nums[ret];
                }

                ++ret;
            }
        }

        return ret;
    }
};
