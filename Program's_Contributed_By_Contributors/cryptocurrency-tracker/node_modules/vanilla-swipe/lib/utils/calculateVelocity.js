"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.calculateVelocity = calculateVelocity;

function calculateVelocity(x, y, time) {
  var magnitude = Math.sqrt(x * x + y * y);
  return magnitude / (time || 1);
}