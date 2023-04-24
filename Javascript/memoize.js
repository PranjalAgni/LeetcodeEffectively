// https://leetcode.com/problems/memoize/

// Time: O(N) | Space: O(N)
/**
 * @param {Function} fn
 */
function memoize(fn) {
    const cache = new Map();
    return function (...args) {
        const key = args.join("-");
        if (cache.has(key)) return cache.get(key);
        const answer = fn(...args);
        cache.set(key, answer);
        return answer;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */