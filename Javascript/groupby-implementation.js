// https://leetcode.com/problems/group-by/

/**
 * @param {Function} fn
 * @return {Array}
 */
// Time: O(N) | Space: O(N)
// Assuming complexity of `fn` is constant
Array.prototype.groupBy = function (fn) {
    const arr = this;
    const groupedAnswer = {};
    const N = arr.length;
    for (let idx = 0; idx < N; idx++) {
        const id = fn(arr[idx]);
        if (!groupedAnswer[id]) groupedAnswer[id] = [];
        groupedAnswer[id].push(arr[idx]);
    }

    return groupedAnswer;

};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */