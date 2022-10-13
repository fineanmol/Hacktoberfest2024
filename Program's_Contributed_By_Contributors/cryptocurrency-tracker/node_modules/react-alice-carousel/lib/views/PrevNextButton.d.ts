/// <reference types="react" />
export declare const PrevNextButton: ({ name, isDisabled, onClick, renderPrevButton, renderNextButton }: Props) => JSX.Element;
declare type Props = {
    name: 'prev' | 'next';
    isDisabled: boolean;
    onClick: (e: any) => void;
    renderPrevButton?: ({ isDisabled }: {
        isDisabled: any;
    }) => any;
    renderNextButton?: ({ isDisabled }: {
        isDisabled: any;
    }) => any;
};
export {};
