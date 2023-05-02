// https://leetcode.com/problems/function-composition/
/**
 * @param {Function[]} functions
 * @return {Function}
 */
// Time: O(N) | Space: O(1)
// Good problem for understanding closures
var compose = function (functions) {
    const N = functions.length;
    return function (x) {
        let accumulatedAnswer = x;
        for (let idx = N - 1; idx >= 0; idx--) {
            const currentFn = functions[idx];
            accumulatedAnswer = currentFn(accumulatedAnswer);
        }

        return accumulatedAnswer;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */