/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function (arr, fn) {
    const result = [];
    const N = arr.length;
    for (let idx = 0; idx < N; idx++) {
        if (fn(arr[idx], idx)) result.push(arr[idx]);
    }

    return result;
};