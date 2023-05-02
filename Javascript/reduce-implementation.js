// https://leetcode.com/problems/array-reduce-transformation/

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
// Time: O(N) | Space: O(1)
var reduce = function (nums, fn, init) {
    const N = nums.length;
    let answer = init;
    for (let idx = 0; idx < N; idx++) {
        answer = fn(answer, nums[idx], idx);
    }

    return answer;
};
