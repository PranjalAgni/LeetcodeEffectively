// https://leetcode.com/problems/nested-array-generator/

/**
 * @param {Array} arr
 * @return {Generator}
 */
var inorderTraversal = function* (multiDimensionalArr) {
    for (const elt of multiDimensionalArr) {
        const type = typeof elt;
        if (type === "number") yield elt;
        else {
            yield* inorderTraversal(elt);
        }
    }
};

/**
 * const gen = inorderTraversal([1, [2, 3]]);
 * gen.next().value; // 1
 * gen.next().value; // 2
 * gen.next().value; // 3
 */