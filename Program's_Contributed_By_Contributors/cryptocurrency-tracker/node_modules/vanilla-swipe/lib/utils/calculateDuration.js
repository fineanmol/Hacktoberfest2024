"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.calculateDuration = calculateDuration;

function calculateDuration() {
  var prevTime = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : 0;
  var nextTime = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;
  return prevTime ? nextTime - prevTime : 0;
}