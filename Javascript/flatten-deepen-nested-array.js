// https://leetcode.com/problems/flatten-deeply-nested-array/

/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */

// Time: O(N) | Space: O(N)
function flatRecursive(flattenedArr, arr, currentDepth, maxDepth) {
    for (let idx = 0; idx < arr.length; idx++) {
        const elt = arr[idx];
        if (Array.isArray(elt) && currentDepth < maxDepth) {
            flatRecursive(flattenedArr, elt, currentDepth + 1, maxDepth);
        } else {
            flattenedArr.push(elt);
        }
    }
}

var flat = function (arr, n) {
    if (n == 0) return arr;
    const flattenedArr = [];
    flatRecursive(flattenedArr, arr, 0, n);
    return flattenedArr;
};