// https://leetcode.com/problems/event-emitter/

class EventEmitter {
    constructor() {
        this.eventMap = new Map();
    }
    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        if (!this.eventMap.has(eventName)) this.eventMap.set(eventName, []);
        const existingCallbacks = this.eventMap.get(eventName);
        existingCallbacks.push(callback);
        this.eventMap.set(eventName, existingCallbacks);
        return {
            unsubscribe: () => {
                const subscribedCallbacks = this.eventMap.get(eventName);
                const position = subscribedCallbacks.indexOf(callback);
                subscribedCallbacks.splice(position, 1);
                this.eventMap.set(eventName, subscribedCallbacks);
                return undefined;
            }
        };
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        const callbacks = this.eventMap.get(eventName) || [];
        // if (callbacks.length === 0) return [];
        const answer = [];
        for (const callback of callbacks) {
            answer.push(callback(...args));
        }
        return answer;
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */