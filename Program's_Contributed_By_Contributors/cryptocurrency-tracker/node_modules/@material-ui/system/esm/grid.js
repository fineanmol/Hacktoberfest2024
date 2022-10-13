import style from './style';
import compose from './compose';
export var gridGap = style({
  prop: 'gridGap'
});
export var gridColumnGap = style({
  prop: 'gridColumnGap'
});
export var gridRowGap = style({
  prop: 'gridRowGap'
});
export var gridColumn = style({
  prop: 'gridColumn'
});
export var gridRow = style({
  prop: 'gridRow'
});
export var gridAutoFlow = style({
  prop: 'gridAutoFlow'
});
export var gridAutoColumns = style({
  prop: 'gridAutoColumns'
});
export var gridAutoRows = style({
  prop: 'gridAutoRows'
});
export var gridTemplateColumns = style({
  prop: 'gridTemplateColumns'
});
export var gridTemplateRows = style({
  prop: 'gridTemplateRows'
});
export var gridTemplateAreas = style({
  prop: 'gridTemplateAreas'
});
export var gridArea = style({
  prop: 'gridArea'
});
var grid = compose(gridGap, gridColumnGap, gridRowGap, gridColumn, gridRow, gridAutoFlow, gridAutoColumns, gridAutoRows, gridTemplateColumns, gridTemplateRows, gridTemplateAreas, gridArea);
export default grid;