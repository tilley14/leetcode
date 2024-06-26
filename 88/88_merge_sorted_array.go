package main

import (
	"fmt"
	"reflect"
)

func merge(nums1 []int, m int, nums2 []int, n int) {
	tmp1 := make([]int, len(nums1))
	copy(tmp1, nums1)

	j := 0
	k := 0

	for i := 0; i < m+n-1; i++ {
		if j >= m {
			nums1[i] = nums2[k]
			k++
			continue
		}
		if k >= n {
			nums1[i] = tmp1[j]
			j++
			continue
		}

		if tmp1[j] <= nums1[k] {
			nums1[i] = tmp1[j]
			j++
		} else {
			nums1[i] = nums2[k]
			k++
		}
	}

}

func main() {
	solution1 := [6]int{1, 2, 2, 3, 5, 6}
	nums11 := [6]int{1, 2, 3, 0, 0, 0}
	nums21 := [3]int{2, 5, 6}
	merge(nums11[0:], 3, nums21[0:], 3)
	fmt.Println(nums11)
	fmt.Println(reflect.DeepEqual(solution1, nums11))

	solution2 := [1]int{1}
	nums12 := [1]int{1}
	nums22 := [0]int{}
	merge(nums12[0:], 1, nums22[0:], 0)
	fmt.Println(nums12)
	fmt.Println(reflect.DeepEqual(solution2, nums12))

	solution3 := [1]int{1}
	nums13 := [1]int{0}
	nums23 := [1]int{1}
	merge(nums13[0:], 0, nums23[0:], 1)
	fmt.Println(nums13)
	fmt.Println(reflect.DeepEqual(solution3, nums13))
}
