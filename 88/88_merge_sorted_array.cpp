class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1;
        int j = m - 1, k = n - 1;
        for ( ; j >= 0 && k >= 0; --i) {
            if (nums1[j] > nums2[k]) {
                nums1[i] = nums1[j];
                --j;
            } else {
                nums1[i] = nums2[k];
                --k;
            }
        }

        while (k >= 0) {
            nums1[i] = nums2[k];
            --k; --i;
        }
    }
};

