import style from './style';
import compose from './compose';

function getBorder(value) {
  if (typeof value !== 'number') {
    return value;
  }

  return "".concat(value, "px solid");
}

export var border = style({
  prop: 'border',
  themeKey: 'borders',
  transform: getBorder
});
export var borderTop = style({
  prop: 'borderTop',
  themeKey: 'borders',
  transform: getBorder
});
export var borderRight = style({
  prop: 'borderRight',
  themeKey: 'borders',
  transform: getBorder
});
export var borderBottom = style({
  prop: 'borderBottom',
  themeKey: 'borders',
  transform: getBorder
});
export var borderLeft = style({
  prop: 'borderLeft',
  themeKey: 'borders',
  transform: getBorder
});
export var borderColor = style({
  prop: 'borderColor',
  themeKey: 'palette'
});
export var borderRadius = style({
  prop: 'borderRadius',
  themeKey: 'shape'
});
var borders = compose(border, borderTop, borderRight, borderBottom, borderLeft, borderColor, borderRadius);
export default borders;