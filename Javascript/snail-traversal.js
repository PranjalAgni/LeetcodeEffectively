// https://leetcode.com/problems/snail-traversal/

// Nice problem think about more optimizations and less loops

function makeMatrix(rowsCount, colsCount) {
    const matrix = [];
    while (rowsCount-- > 0) {
        let row = [];
        for (let idx = 0; idx < colsCount; idx++) {
            row.push(0);
        }
        matrix.push(row);
    }

    return matrix;
}

/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function (rowsCount, colsCount) {
    const N = this.length;
    if (rowsCount * colsCount !== N) return [];
    const snailled = makeMatrix(rowsCount, colsCount);
    let colIdx = 0;
    let pos = 0;

    while (colIdx < colsCount) {
        if (colIdx % 2 == 0) {
            for (let row = 0; row < rowsCount; row++) {
                snailled[row][colIdx] = this[pos];
                pos += 1;
            }
        } else {
            for (let row = rowsCount - 1; row >= 0; row--) {
                snailled[row][colIdx] = this[pos];
                pos += 1;
            }
        }

        colIdx += 1;
    }

    return snailled;

}

