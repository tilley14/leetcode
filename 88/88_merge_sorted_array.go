/*
*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

package main

import (
	"fmt"
	"reflect"
)

func merge(nums1 []int, m int, nums2 []int, n int) {
	// Temp copy of nums1 because nums1 is an out parameter
	// An improvement could be to try and do this in place
	tmp1 := make([]int, len(nums1))
	copy(tmp1, nums1)

	i := 0
	j := 0
	k := 0

	// Merge until we have merged all elements of nums1 or nums2
	for ; j < m && k < n; i++ {
		if tmp1[j] < nums2[k] {
			nums1[i] = tmp1[j]
			j++
		} else {
			nums1[i] = nums2[k]
			k++
		}
	}

	// Merge the remaining elements
	for j < m {
		nums1[i] = tmp1[j]
		j++
		i++
	}

	for k < n {
		nums1[i] = nums2[k]
		k++
		i++
	}
}

// Mergin' Bakrds!
func merge_bakrds(nums1 []int, m int, nums2 []int, n int) {
	// Merging backwards avoids having to do the copy
	i := m + n - 1
	j := m - 1
	k := n - 1

	// Merge until we have merged all elements of nums1 or nums2
	for ; j >= 0 && k >= 0; i-- {
		if nums1[j] >= nums2[k] {
			nums1[i] = nums1[j]
			j--
		} else {
			nums1[i] = nums2[k]
			k--
		}
	}

	// Merge the remaining elements
	for j >= 0 {
		nums1[i] = nums1[j]
		j--
		i--
	}

	for k >= 0 {
		nums1[i] = nums2[k]
		k--
		i--
	}
}

func main() {
	solution1 := []int{1, 2, 2, 3, 5, 6}
	nums11 := []int{1, 2, 3, 0, 0, 0}
	nums21 := []int{2, 5, 6}
	merge(nums11, 3, nums21, 3)
	fmt.Println(nums11)
	fmt.Println(reflect.DeepEqual(solution1, nums11))

	solution2 := []int{1}
	nums12 := []int{1}
	nums22 := []int{}
	merge(nums12, 1, nums22, 0)
	fmt.Println(nums12)
	fmt.Println(reflect.DeepEqual(solution2, nums12))

	solution3 := []int{1}
	nums13 := []int{0}
	nums23 := []int{1}
	merge(nums13, 0, nums23, 1)
	fmt.Println(nums13)
	fmt.Println(reflect.DeepEqual(solution3, nums13))
}
