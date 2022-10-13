"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.calculateMovingPosition = calculateMovingPosition;

function calculateMovingPosition(e) {
  if ('changedTouches' in e) {
    var touches = e.changedTouches && e.changedTouches[0];
    return {
      x: touches && touches.clientX,
      y: touches && touches.clientY
    };
  }

  return {
    x: e.clientX,
    y: e.clientY
  };
}