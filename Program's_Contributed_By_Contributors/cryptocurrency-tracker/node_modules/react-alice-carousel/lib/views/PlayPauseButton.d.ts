/// <reference types="react" />
export declare const PlayPauseButton: ({ isPlaying, onClick, renderPlayPauseButton }: Props) => JSX.Element;
declare type Props = {
    isPlaying: boolean;
    onClick: (e: any) => void;
    renderPlayPauseButton?: ({ isPlaying }: {
        isPlaying: any;
    }) => any;
};
export {};
