// https://leetcode.com/problems/crawler-log-folder/

// Time: O(N) | Space: O(1)
/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function (logs) {
    let folders = [];
    for (const log of logs) {
        if (log === "../") {
            folders.pop();
        } else if (log !== "./") {
            folders.push(log);
        }
    }

    return folders.length;
};