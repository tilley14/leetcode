class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> num_freqs;
        
        int max_elm = 0;
        int max_freq = 0;

        // const int maj_thresh = nums.size() / 2;

        for (const auto &n : nums) {
            auto &f = num_freqs[n];
            ++f;

            if (f > max_freq) {
                max_elm  = n;
                max_freq = f;

                // For small lists this is just ogoing to slow everything down
                // if (max_freq > maj_thresh) {
                //     break;
                // }
            }
        }

        return max_elm;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2);
    }
};

// boyer-moore-majority-voting-algorithm
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int elm = -1;
        int count = 0;

        for (int n : nums) {
            if (count == 0) {
                elm = n;
            }
            count += (elm == n)? 1 : -1;
        } 

        // We don't need to verify that elm's occurance is > n/2 becuase
        // that was guaranteed in the problem statement        
        return elm;
    }
};
