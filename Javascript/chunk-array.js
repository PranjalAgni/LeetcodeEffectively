// https://leetcode.com/problems/chunk-array/
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
// Time: O(N) | Space: O(N)
// N = length of size
var chunk = function (arr, size) {
    const N = arr.length;
    let pos = 1;
    let idx = 0;
    const answer = [];
    let current = [];
    while (idx < N) {
        current.push(arr[idx]);
        if (pos == size) {
            answer.push(current);
            current = [];
            pos = 0;
        }
        pos += 1;
        idx += 1;
    }

    if (current.length) answer.push(current);
    return answer;
};
