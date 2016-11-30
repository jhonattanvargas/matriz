/*
var items = [
  [1, 2],
  [3, 4],
  [5, 6]
];
console.log(items[0][0]); // 1
console.log(items);

var myJsonString = JSON.stringify(items);
console.log(myJsonString)
*/

let addon = require('./build/Release/addon')

var x = new Array(3);
for (var i = 0; i < x.length; i++) {
  x[i] = new Array(3);
  for (var j = 0; j < x[i].length; j++) {
    x[i][j] = i+j;
  }
}

var y = new Array(3);
for (var i = 0; i < y.length; i++) {
  y[i] = new Array(3);
  for (var j = 0; j < y[i].length; j++) {
    y[i][j] = i+j+1;
  }
}

//addon.showArray(x)
var s = addon.showArray(x,y)
console.log(s)
