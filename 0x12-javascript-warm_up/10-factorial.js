#!/usr/bin/node
function rec (a) {
  const num = parseInt(a);
  if (isNaN(num) || num < 0) {
    return 1;
  }
  if (num === 0 || num === 1) {
    return 1;
  }
  return num * rec(num - 1);
}
const num = process.argv[2];
console.log(rec(num));
