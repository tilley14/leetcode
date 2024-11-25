class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int tail = 0;
        bool dup = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                ++tail;
                continue;
            }

            const auto &cur  = nums.at(i);
            const auto &prev = nums.at(i - 1);
            if (cur == prev) {
                // Skip after we have seen a duplicate.
                // We are going to write over this so dont move the tail
                if (dup) {
                    continue;
                } else {
                    dup = true;
                }
            } else {
                dup = false;
            }

            nums[tail] = nums.at(i);
            ++tail;
        }

        return tail;
    }
};
