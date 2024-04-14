// https://leetcode.com/problems/join-two-arrays-by-id/

// Thoughts:
// 1. We need to keep a map to track which ids are present across arrays
// 2. Once we get a object present in both list, we need to think of resolving the keys
// 3. resolveConflict() function overrides previous object with all the keys present in current object
// 4. Also remember we need to return the answer sorted by the id keys
// 5. So we sort the uniqueIds set with help of numeralSort
// 6. Now just loop over mergedMap and fill my answerList


function resolveConflict(previous, current) {
    const resolvedObj = previous;
    Object.keys(current).forEach(key => {
        resolvedObj[key] = current[key];
    });

    return resolvedObj;
}

function numeralSort(a, b) {
    return a - b;
}

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function (arr1, arr2) {
    const ids = []
    const mergedMap = new Map();
    for (const obj of arr1) {
        ids.push(obj.id);
        mergedMap.set(obj.id, obj);
    }

    for (const obj of arr2) {
        ids.push(obj.id);
        if (mergedMap.has(obj.id)) {
            const resolvedObject = resolveConflict(mergedMap.get(obj.id), obj);
            mergedMap.set(obj.id, resolvedObject);
        } else {
            mergedMap.set(obj.id, obj);
        }
    }

    const uniqueSortedIds = new Set([...ids.sort(numeralSort)]);

    const answer = [];
    for (const id of uniqueSortedIds) {
        answer.push(mergedMap.get(id));
    }

    return answer;

};