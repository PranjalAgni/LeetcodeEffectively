// https://leetcode.com/problems/cache-with-time-limit/

var TimeLimitedCache = function () {
    this.cache = new Map();
    this.timeoutId = new Map();
};

// Time: O(N) | Space: O(2N)
/** 
 * @param {number} key
 * @param {number} value
 * @param {number} time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
    const isAlreadyPresent = this.cache.has(key);
    if (isAlreadyPresent) {
        const id = this.timeoutId.get(key);
        clearTimeout(id);
    }
    this.cache.set(key, value);
    const timeoutId = setTimeout(() => {
        this.cache.delete(key);
        clearTimeout(timeoutId);
    }, duration);

    this.timeoutId.set(key, timeoutId);
    return isAlreadyPresent;
};

// Time: O(N) | Space: O(1)
/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
    return this.cache.has(key) ? this.cache.get(key) : -1;
};

// Time: O(N) | Space: O(1)
/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
    return this.cache.size;
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */