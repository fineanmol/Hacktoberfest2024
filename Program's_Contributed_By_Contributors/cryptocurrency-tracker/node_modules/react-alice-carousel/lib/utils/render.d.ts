import { State } from '../types';
export declare const getActiveSlideIndex: (isNextSlideDisabled: any, state: State) => number;
export declare const getActiveSlideDotsLength: (slidesLength?: number, itemsInSlide?: number) => number;
export declare const getSlideIndexForNonMultipleItems: (activeIndex: any, itemsInSlide: any, slidesLength: any) => number;
export declare const getSlideIndexForMultipleItems: (activeIndex: any, itemsInSlide: any, slidesLength: any, isNextSlideDisabled: any) => number;
export declare const getSlideInfo: (activeIndex?: number, itemsCount?: number) => {
    item: number;
    itemsCount: number;
};
export declare const getSlideItemInfo: (state: State) => {
    isPrevSlideDisabled: boolean;
    isNextSlideDisabled: boolean;
};
