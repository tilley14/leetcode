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
