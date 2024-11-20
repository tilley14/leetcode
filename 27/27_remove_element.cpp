class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) != val) {
                if (ret != i) {
                    nums[ret] = nums.at(i);
                    // was swapping, but we can cheat because we know what the
                    // value we are swapping with is going to be...
                    // Actually, we dont even need to swap based on the how this is evaluated because it only
                    // looks at the first ret values
                    // nums[i] = val;
                }

                ++ret;
            }
        }

        return ret;
    }
};
