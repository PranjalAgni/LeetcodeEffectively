// https://leetcode.com/problems/array-prototype-last/

// Time: O(1) | Space: O(1)
Array.prototype.last = function () {
    const N = this.length;
    return (N === 0 ? -1 : this[N - 1]);
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */