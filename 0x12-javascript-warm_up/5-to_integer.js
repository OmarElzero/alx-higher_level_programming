#!/usr/bin/node

const argsValue = process.argv[2];

if (Number.isInteger(parseInt(argsValue))) {
  console.log(`My number: ${parseInt(argsValue)}`);
} else {
  console.log('Not a number');
}
