// https://leetcode.com/problems/convert-object-to-json-string/

// Example
/**
Input: object = {"y":1,"x":2}
Output: {"y":1,"x":2}
Explanation: 
Return the JSON representation.
Note that the order of keys should be the same as the order returned by Object.keys().
*/

// Currently the solution is WIP need to clean it as well

/**
 * @param {any} object
 * @return {string}
 */
let answer = "{";
function jsonStringifyRec(object) {
   Object.entries(object).forEach(([key, value]) => {
      answer += `"${key}"`;
      if (value !== null && Array.isArray(value)) {
        answer += "[";
        value.forEach(elt => {
          answer += String(elt) + ",";
        });
        answer += "]";
      }
      else if (value !== null && typeof value === "object") {
        answer += `:{`
        jsonStringifyRec(value);
        answer += `}`
        
      }
      else {
        answer += `:${value},`;
      }
    });
}

var jsonStringify = function(object) {
    const objType = typeof object;
    if (objType !== "object") return object;
    jsonStringifyRec(object);
    answer += "}";
    return answer;
};