// https://leetcode.com/problems/json-deep-equal/
/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
// Currently WIP
var areDeeplyEqual = function (o1, o2) {
    const typeO1 = typeof o1;
    const typeO2 = typeof o2;
    if (typeO1 !== typeO2) return false;
    if (typeO1 !== "object" && typeO2 !== "object") {
        console.log("This is a object");
        return JSON.stringify(o1) === JSON.stringify(o2);
    }
    const N = Object.keys(o1).length;
    const M = Object.keys(o2).length;
    if (N != M) return false;

    const keys1 = Object.keys(o1);
    // const keys2 = Object.keys(o2);

    for (const key of keys1) {
        if (JSON.stringify(o1[key]) !== JSON.stringify(o2[key])) return false;
    }

    return true;

};
