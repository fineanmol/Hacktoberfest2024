"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.rotateByAngle = rotateByAngle;

function rotateByAngle(position) {
  var angle = arguments.length > 1 && arguments[1] !== undefined ? arguments[1] : 0;

  if (angle === 0) {
    return position;
  }

  var x = position.x,
      y = position.y;
  var angleInRadians = Math.PI / 180 * angle;
  var rotatedX = x * Math.cos(angleInRadians) + y * Math.sin(angleInRadians);
  var rotatedY = y * Math.cos(angleInRadians) - x * Math.sin(angleInRadians);
  return {
    x: rotatedX,
    y: rotatedY
  };
}