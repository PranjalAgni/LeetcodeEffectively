// https://leetcode.com/problems/call-function-with-custom-context/

// TODO: Understand its usecases and attaching context to objects

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