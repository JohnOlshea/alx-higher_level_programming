#!/usr/bin/node

function add(a, b) {
  const c = a + b;
  console.log(c);
}

const arg1 = process.argv[2];
const arg2 = process.argv[3];

if (arg1 !== undefined && arg2 !== undefined) {
  add(Number(arg1), Number(arg2));
} else {
  console.log("NaN");
}
