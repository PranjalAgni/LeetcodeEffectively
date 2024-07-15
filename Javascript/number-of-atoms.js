// https://leetcode.com/problems/number-of-atoms/

// Amazing problem solved using stack of maps
// Detailed discussion post: https://leetcode.com/problems/number-of-atoms/discuss/5474227/Explanations-No-One-Will-Give-YouVery-Detailed-ApproachExtremely-Simple-And-Effective


// Time: O(N*N) | Space: O(N)

/**
 * @param {string} formula
 * @return {string}
 */
function isSmallCased(char) {
    return (char >= 'a' && char <= 'z');
}

function isDigit(char) {
    return (char >= '0' && char <= '9');
}

function getSortedAtom(obj) {
    let atoms = [];
    Object.keys(obj).forEach((key) => {
        atoms.push(key);
    });

    return atoms.sort();
}

function constructAnswer(atomsList, obj) {
    let answer = "";

    for (const atom of atomsList) {
        answer += atom;
        if (obj[atom] > 1) answer += String(obj[atom]);
    }

    return answer;
}

var countOfAtoms = function (formula) {
    const N = formula.length;
    let stack = [];
    let finalResult = {};
    let pos = 0;

    while (pos < N) {
        // what we can have [A-Z] [a-z] [0-9] ( )
        const ch = formula[pos];
        let multiplier = "";
        let atom = "";
        if (ch === '(') {
            stack.unshift({});
        } else if (ch === ')') {
            let nextPos = pos + 1;
            while (nextPos < N && isDigit(formula[nextPos])) {
                multiplier += formula[nextPos];
                nextPos += 1;
            }

            if (!multiplier) multiplier = "1";
            let target = stack.shift();

            Object.keys(target).forEach((key) => {
                target[key] *= Number(multiplier);
            });

            let isFromStack = stack.length > 0;
            let main = (stack.length === 0 ? finalResult : stack.shift());

            // merge the multiplied keys to main
            Object.keys(target).forEach((key) => {
                if (main[key]) {
                    main[key] += target[key];
                } else {
                    main[key] = target[key];
                }
            });

            if (isFromStack) {
                stack.unshift(main);
            } else {
                finalResult = main;
            }

            pos = nextPos - 1;
        } else {
            // assuming pos will always be in A-Z
            atom += ch;
            let nextPos = pos + 1;

            while (nextPos < N && isSmallCased(formula[nextPos])) {
                atom += formula[nextPos];
                nextPos += 1;
            }

            while (nextPos < N && isDigit(formula[nextPos])) {
                multiplier += formula[nextPos];
                nextPos += 1;
            }

            if (!multiplier) multiplier = "1";

            let isFromStack = stack.length > 0;
            let target = (stack.length === 0 ? finalResult : stack.shift());
            if (!target[atom]) target[atom] = 0;
            target[atom] += Number(multiplier);
            if (isFromStack) {
                stack.unshift(target);
            } else {
                finalResult = target;
            }

            pos = nextPos - 1;
        }

        pos += 1;
    }

    const sortedAtoms = getSortedAtom(finalResult);
    return constructAnswer(sortedAtoms, finalResult);
};