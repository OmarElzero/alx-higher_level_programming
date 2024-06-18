#!/usr/bin/node

if (process.argv.length <= 3) {
  console.log(0);
} else {
  let max1 = -Infinity;
  let max2 = -Infinity;

  for (let i = 2; i < process.argv.length; i++) {
    const num = parseInt(process.argv[i]);
    if (num > max1) {
      max2 = max1;
      max1 = num;
    } else if (num > max2 && num < max1) {
      max2 = num;
    }
  }

  console.log(max2);
}
