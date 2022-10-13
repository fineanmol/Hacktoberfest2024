import { Transformations, Props, State, RootElement, Transition, Style } from '../types';
export declare const getSlides: (props: Props) => any;
export declare const getItemsCount: (props: Props) => any;
export declare const getItemsOffset: (props: Props) => 0 | 1;
export declare const createClones: (props: Props) => any;
export declare const isElement: (element: any) => boolean;
export declare const createAutowidthTransformationSet: (el: any, stageWidth?: number, infinite?: boolean) => Transformations;
export declare const createDefaultTransformationSet: (children: unknown[], stageWidth: number, itemsInSlide: number, infinite?: boolean) => Transformations;
export declare const getItemWidth: (galleryWidth: number, itemsInSlide: number) => number;
export declare function getElementDimensions(element: any): {
    width: any;
    height: any;
};
export declare const getAutoheightProperty: (stageComponent: Element, props: Props, state: State) => number | undefined;
export declare const getElementCursor: (props: Props, state: State) => number;
export declare const getElementFirstChild: (stageComponent: any, cursor: any) => any;
export declare function shouldHandleResizeEvent(e: Event, prevDimensions?: RootElement, nextRootComponentDimensions?: RootElement): boolean;
export declare function animate(element: any, options: any): any;
export declare const getRenderWrapperStyles: (props: Props, state: State, element: any) => {
    height: number | undefined;
    transition: string | undefined;
    paddingLeft: string;
    paddingRight: string;
};
export declare const getTransitionProperty: (options?: Transition | undefined) => string;
export declare const getRenderStageStyles: (nextStyles: any, currentStyles: Style) => Style;
export declare const getRenderStageItemStyles: (i: number, state: State) => {
    transform: string;
    animationDuration: string;
    width: string;
} | {
    width: number;
    transform?: undefined;
    animationDuration?: undefined;
};
export declare const getTranslate3dProperty: (nextIndex: any, state: Partial<State>) => number;
export declare const getTouchmoveTranslatePosition: (deltaX: number, translate3d: number) => number;
export declare function getTranslateXProperty(element: any): number;
export declare function getTransformMatrix(element: any): RegExpMatchArray;
