#!/usr/bin/node
function add (a, b) {
  return parseInt(a) + parseInt(b);
}
const num = process.argv[2];
const num2 = process.argv[3];
console.log(add(num, num2));
