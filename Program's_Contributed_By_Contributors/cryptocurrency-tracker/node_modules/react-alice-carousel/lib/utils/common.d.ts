import { Props, State } from '../types';
export declare const canUseDOM: () => boolean;
export declare const concatClassnames: (...classes: any[]) => string;
export declare const getIsStageContentPartial: (infinite?: boolean, stageWidth?: number, contentWidth?: number) => boolean;
export declare const getItemsInSlide: (itemsCount: number, props: Props) => number;
export declare const calculateInitialState: (props: Partial<Props>, el: null | HTMLElement, canUseDom?: boolean) => State;
