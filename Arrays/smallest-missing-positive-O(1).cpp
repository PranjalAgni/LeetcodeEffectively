// Given a list of integers nums, find the first missing positive integer. In
// other words, find the lowest positive integer that does not exist in the
// list. The list can contain duplicates and negative numbers as well.

// Time: O(N) | Space: O(1)
int solve(vector<int>& nums) {
    int N = nums.size();

    int start = 0;
    // swap the element at index nums[i] with nums[nums[i]]
    // it means keeping the ith element at ith position
    // element 1 at 1st index, 2 at 2nd index and so on you get the idea
    while (start < N) {
        int elt = nums[start];
        if (elt > 0 && elt <= N && nums[start] != nums[elt - 1]) {
            swap(nums[elt - 1], nums[start]);
            start -= 1;
        }
        start += 1;
    }

    // now its sure, that the first missing positive element will be which is
    // not matching its index index + 1 != nums[index]
    start = 0;
    while (start < N) {
        if (start + 1 != nums[start]) return start + 1;
        start += 1;
    }

    return start + 1;
}