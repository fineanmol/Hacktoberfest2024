import type { Node } from 'postcss-selector-parser';
export default function selectorSpecificity(node: Node): {
    a: number;
    b: number;
    c: number;
};
