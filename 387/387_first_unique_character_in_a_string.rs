use std::collections::HashMap;

struct Solution {}

impl Solution {
    pub fn first_uniq_char(_s: String) -> i32 {
        // let mut chars = HashMap::new();

        // for (i, c) in s.chars().enumerate() {
            
        // }

        // for (c, &i) in contacts.iter() {
        // }

        return -1;
    }
}


fn main() {
    println!("Case 1 {}", Solution::first_uniq_char(String::from("leetcode")) == 0);
    println!("Case 2 {}", Solution::first_uniq_char(String::from("loveleetcode")) == 2);
    println!("Case 3 {}", Solution::first_uniq_char(String::from("aabb")) == -1);
}
