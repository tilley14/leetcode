class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Naive
        // Copy the vector to a temp container
        // Start at index k in the original vector
        // Copy from the front of the temp container to the (k+n)%size index of the original
        
        // Space: O(n)
        const auto tmp = nums;

        // Time: 0(n)
        for (int i = 0; i < nums.size(); ++i) {
            nums[(i+k)%nums.size()] = tmp[i];
        }
        
        // Total Time Complexity: O(n)
        // Total Space Complexity: O(n)
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // With only k extra space...
        // Create a buffer vector of length k
        // Copy the [k,k+k] elements into the buffer
        // move the [0,k] elements into the [k,k+k] spots
        // iterate from k+k+1 -> (n+k)%n storing elements that would be written over into the buffer

        if (k == 0 || nums.size() <= 1) {
            return;
        }

        k = k % nums.size();

        const int n = nums.size();
        std::vector<int> buf;
        int i = 0;
        // Space: O(k)
        // Time: O(k)
        for ( ; i < k; ++i) {
            buf.push_back(nums[(i+k)%n]);
            nums[(i+k)%n] = nums[i];
        }

        int tmp = 0;
        // Time: O(n - k)
        // Space: O(1)
        for ( ; i < n; ++i) {
            tmp = nums[(i+k)%n];
            nums[(i+k)%n] = buf[i % buf.size()];
            buf[i % buf.size()] = tmp;
        }

        // Total Time Complexity: O(k) + O(n-k) = O(n)
        // Total Space Complexity: O(k) + O(1)
    }
};


// Try with O(1) extra space
// Hint try reversing the array or sections of the array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reverse the entire array
        // veverse the first k elements
        // reverse the last n-k elements

        k = k % nums.size();
        if (k == 0 || nums.size() <= 1) {
            return;
        }

        // Space: O(1)
        // Time: O(k/2)
        auto reverseSlice = [](std::vector<int>& array, int start, int end) -> void {
            for (int i = 0; i <= (end - start) / 2; ++i) {
                int tmp = array[end-i];
                array[end - i] = array[start + i];
                array[start + i] = tmp;
            }
        };

        // Time: O(n/2)
        reverseSlice(nums, 0, nums.size() - 1);
        // Time: O(k/2)
        reverseSlice(nums, 0, k - 1);
        // Time: O((n-k)/2)
        reverseSlice(nums, k, nums.size() - 1);

        

        // Total Time Complexity:  O(n/2) + O(k/2) + O((n-k)/2)
        // Total Space Complexity: O(1)
    }
};