class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (auto i = nums1.size() - 1; i >= 0 && n > 0 && m > 0; --i) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[i] = nums1[m - 1];
                --m;
            } else {
                nums1[i] = nums2[n - 1];
                --n;
            }
        }

        while (n) {
            nums1[n - 1] = nums2[n - 1];
            --n;
        }
    }
};
