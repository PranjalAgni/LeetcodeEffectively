// https://leetcode.com/problems/compare-version-numbers/
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
// Time: O(N + M) | Space: O(N + M)
var compareVersion = function (version1, version2) {
    const v1List = version1.split(".").map(Number);
    const v2List = version2.split(".").map(Number);

    const N = v1List.length;
    const M = v2List.length;
    const len = Math.min(N, M);
    for (let idx = 0; idx < len; idx++) {
        if (v1List[idx] > v2List[idx]) return 1;
        if (v1List[idx] < v2List[idx]) return -1;
    }

    for (let idx = len; idx < N; idx++) {
        if (v1List[idx] > 0) return 1;
    }

    for (let idx = len; idx < M; idx++) {
        if (v2List[idx] > 0) return -1;
    }

    return 0;
};