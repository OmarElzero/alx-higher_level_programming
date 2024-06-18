#!/usr/bin/node

const argsValue = process.argv;

if (!argsValue[2]) {
  console.log('No argument');
} else {
  console.log(argsValue[2]);
}
