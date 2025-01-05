// Naive
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Loop i through the vector from start to n-1
            // Loop j from i+1 to n,
               // add the elements at i and j and return [i, j] if the elments sum to target

        // Time: O(n)
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Time: O(n)
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums.at(i) + nums.at(j) == target) {
                    return {i, j};
                }
            }
        }  

        return {-1, -1};

        // Total Space Complexity: O(1)
        // Total Time Complexity: O(n)*O(n) = O(n^2)
    }
};

// Better than O(n2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // loop through the vector nums
        // take the difference between the val at index i and target
        // store the difference in a map that is <difference, index>
        // if the value at the current index is in the map, return [i, map[diff]]

        std::unordered_map<int, int> cache;
        // Time: O(n)
        for (int i = 0; i < nums.size(); ++i) {
            const auto &v = nums[i];
            // Time: O(1)
            auto it = cache.find(v);
            if (it != cache.end()) {
                // Space O(n)
                return {i, it->second};
            } else {
                cache[target - v] = i;
            }
        }

        return {-1, -1};

        // Total Space Complexity: O(n)
        // Total Time Complexity: O(n)*O(1) = O(n)
    }
};

// Two Pointer Method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Put the vector into a new vector of pairs of the value to the orgiginal index
        // Start with a pointer to the beginning and end of the new vector
        // If the sum is greater than the target, move the right pointer to the left
        // If the sum is less than the target, move the left pointer to the right
        // return when the sum == target

        // Space: O(n)
        std::vector<std::pair<int, int>> cache;

        // Time: 0(n)
        for (int i  = 0; i < nums.size(); ++i) {
            cache.push_back({nums.at(i), i});
        }

        // Time: O(nlog(n))
        std::sort(cache.begin(), cache.end(), [](const auto &lhs, const auto &rhs) { return lhs.first < rhs.first; });

        int left = 0;
        int right = cache.size() - 1;

        // Time: O(n)
        while (left != right) {
            int sum = cache.at(left).first + cache.at(right).first;
            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                return { cache.at(left).second, cache.at(right).second };
            }
        }

        return {-1, -1};

        // Total Space Complexity: O(n)
        // Total Time Complexity: O(nlog(n)) + O(n) = O(nlog(n))
    }
};