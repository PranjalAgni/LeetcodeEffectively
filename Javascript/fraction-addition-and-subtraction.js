// https://leetcode.com/problems/fraction-addition-and-subtraction/

// Interesting implementation problem solved
function gcd(a, b) {
    if (a === 0) return b;
    return gcd(b % a, a);
}

// Time: O(N) | Space: O(N)
/**
 * @param {string} expression
 * @return {string}
 */
var fractionAddition = function (expression) {
    const N = expression.length;
    let pos = 0;
    let sign = "+";
    let num = 0;
    const numerators = [];
    const denominators = [];

    while (pos < N) {
        const ch = expression[pos];
        if (ch === '+' || ch === '-') {
            if (num !== 0) {
                denominators.push(num);
                num = 0;
            }
            sign = ch;
        } else if (ch >= '0' && ch <= '9') {
            num = num * 10 + Number(ch);
        } else if (ch === "/") {
            if (sign === "-") num *= -1;
            numerators.push(num);
            num = 0;
            sign = "+";
        }

        pos += 1;
    }

    if (num != 0) denominators.push(num);

    const M = numerators.length;
    let n1 = numerators[0];
    let d1 = denominators[0];

    for (let idx = 1; idx < M; idx++) {
        let n2 = numerators[idx];
        let d2 = denominators[idx];
        let d = d1 * d2;
        let n = (n1 * d2) + (n2 * d1);
        let factor = gcd(Math.abs(n), Math.abs(d));
        n = n / factor;
        d = d / factor;
        n1 = n;
        d1 = d;
    }

    return `${n1}/${d1}`;
};