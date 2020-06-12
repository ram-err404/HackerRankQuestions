/*Quest: [Not much clear. :( ]
 * https://www.hackerrank.com/challenges/swap-nodes-algo/problem
 *
 * Ans: copied from discussion. */


'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(str => str.trim());

    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the swapNodes function below.
 */
function swapNodes(indexes, queries) {
    /*
     * Write your code here.
     */
  const result = [];

    for (let i = 0; i < queries.length; i++) {
        let swapDepth = queries[i];

        let traversed = [];

        traversed = traverseIndices(indexes, swapDepth);
            
        result.push(traversed);
    }

    function traverseIndices(indexes, swapDepth) {
        const traverseIndices = [];

        traverse(indexes, 1, 1);

        function traverse(indexes, index, depth) {
            if (index === -1) {
                return null;
            }

            let leftIndex = indexes[index - 1][0];
            let rightIndex = indexes[index - 1][1];

            if (depth%swapDepth === 0) {
                indexes[index - 1] = [rightIndex, leftIndex];
                [leftIndex, rightIndex] = [rightIndex, leftIndex];
            }

            traverse(indexes, leftIndex, depth + 1);
            traverseIndices.push(index);
            traverse(indexes, rightIndex, depth + 1);
        }
        return traverseIndices;
    }

    return result;
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine(), 10);

    let indexes = Array(n);

    for (let indexesRowItr = 0; indexesRowItr < n; indexesRowItr++) {
        indexes[indexesRowItr] = readLine().split(' ').map(indexesTemp => parseInt(indexesTemp, 10));
    }

    const queriesCount = parseInt(readLine(), 10);

    let queries = [];

    for (let queriesItr = 0; queriesItr < queriesCount; queriesItr++) {
        const queriesItem = parseInt(readLine(), 10);
        queries.push(queriesItem);
    }

    let result = swapNodes(indexes, queries);

    ws.write(result.map(x => x.join(' ')).join("\n") + "\n");

    ws.end();
}

