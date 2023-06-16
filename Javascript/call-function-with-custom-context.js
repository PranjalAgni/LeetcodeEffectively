// https://leetcode.com/problems/call-function-with-custom-context/

// Attaching this context to the object and calling the function which makes this refers to the object passed

/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function (context, ...args) {
    const uniqueId = Symbol();
    context[uniqueId] = this;
    const answer = context[uniqueId](...args);
    delete context[uniqueId];
    return answer;
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */