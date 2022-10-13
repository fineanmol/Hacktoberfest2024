"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.checkIsMoreThanSingleTouches = void 0;

var checkIsMoreThanSingleTouches = function checkIsMoreThanSingleTouches(e) {
  return Boolean(e.touches && e.touches.length > 1);
};

exports.checkIsMoreThanSingleTouches = checkIsMoreThanSingleTouches;