import style from './style';
import compose from './compose';
export var color = style({
  prop: 'color',
  themeKey: 'palette'
});
export var bgcolor = style({
  prop: 'bgcolor',
  cssProperty: 'backgroundColor',
  themeKey: 'palette'
});
var palette = compose(color, bgcolor);
export default palette;