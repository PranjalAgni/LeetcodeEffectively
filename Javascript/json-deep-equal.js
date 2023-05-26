// https://leetcode.com/problems/json-deep-equal/

// Solved 26 March

/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */

const getType = (obj) => {
    if (obj === null) return "null";
    if (Array.isArray(obj)) return "array";
    return typeof obj;
}

var areDeeplyEqual = function (o1, o2) {
    const typeo1 = getType(o1);
    const typeo2 = getType(o2);
    if (typeo1 !== typeo2) return false;
    if (Array.isArray(o1) && Array.isArray(o2)) {
        if (o1.length !== o2.length) return false;
        for (let idx = 0; idx < o1.length; idx++) {
            if (!areDeeplyEqual(o1[idx], o2[idx])) return false;
        }
        return true;
    }
    if (typeo1 === "object" && typeo1 === typeo2) {
        const keys1 = Object.keys(o1);
        const keys2 = Object.keys(o2);
        const N = keys1.length;
        const M = keys2.length;
        if (N != M) return false;
        for (const key of keys1) {
            if (!areDeeplyEqual(o1[key], o2[key])) return false;
        }

        return true;
    }

    return o1 === o2;
};