// https://leetcode.com/problems/convert-object-to-json-string/

// Example
/**
Input: object = {"y":1,"x":2}
Output: {"y":1,"x":2}
Explanation: 
Return the JSON representation.
Note that the order of keys should be the same as the order returned by Object.keys().
*/

// Recursive solution works by checking JS types (number, boolean, array, object)

/**
 * @param {any} object
 * @return {string}
 */

var jsonStringify = function(object) {
    if (object === null) return String(object);
    if (typeof object === "boolean" || typeof object === "number") return object;
    if (typeof object === "string") return `"${object}"`;
    if (Array.isArray(object)) {
       return "[" + object.map(elt => jsonStringify(elt)).join(",") + "]"; 
    }
  
    if (typeof object === "object") {
      return "{" + Object.keys(object).map(key => `"${key}":${jsonStringify(object[key])}`).join(",") + "}";
    }
};