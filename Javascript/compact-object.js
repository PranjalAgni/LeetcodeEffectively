// https://leetcode.com/problems/compact-object/
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (typeof obj === "object") {
        if (Array.isArray(obj)) {
            const list = [];
            for (let idx = 0; idx < obj.length; idx++) {
                if (Boolean(obj[idx])) {
                    list.push(compactObject(obj[idx]));
                }
            }
            return list;
        } else {
            const currObj = {};
            for (const key in obj) {
                if (Boolean(obj[key])) {
                    currObj[key] = compactObject(obj[key]);
                }
            }

            return currObj;
        }
    }

    return obj;
};