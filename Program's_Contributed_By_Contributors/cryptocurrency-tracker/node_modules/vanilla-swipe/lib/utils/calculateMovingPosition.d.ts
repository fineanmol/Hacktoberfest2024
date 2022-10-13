export declare function calculateMovingPosition<T extends E>(e: TouchEvent | MouseEvent | T): {
    x: any;
    y: any;
};
declare type E = {
    clientX: number;
    clientY: number;
    changedTouches?: {
        clientX: number;
        clientY: number;
    }[];
    preventDefault?: Function;
};
export {};
