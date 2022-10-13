/// <reference types="react" />
import type { Location, Path, To } from "history";
export declare function invariant(cond: any, message: string): asserts cond;
export declare function warning(cond: any, message: string): void;
export declare function warningOnce(key: string, cond: boolean, message: string): void;
declare type ParamParseFailed = {
    failed: true;
};
declare type ParamParseSegment<Segment extends string> = Segment extends `${infer LeftSegment}/${infer RightSegment}` ? ParamParseSegment<LeftSegment> extends infer LeftResult ? ParamParseSegment<RightSegment> extends infer RightResult ? LeftResult extends string ? RightResult extends string ? LeftResult | RightResult : LeftResult : RightResult extends string ? RightResult : ParamParseFailed : ParamParseFailed : ParamParseSegment<RightSegment> extends infer RightResult ? RightResult extends string ? RightResult : ParamParseFailed : ParamParseFailed : Segment extends `:${infer Remaining}` ? Remaining : ParamParseFailed;
export declare type ParamParseKey<Segment extends string> = ParamParseSegment<Segment> extends string ? ParamParseSegment<Segment> : string;
/**
 * The parameters that were parsed from the URL path.
 */
export declare type Params<Key extends string = string> = {
    readonly [key in Key]: string | undefined;
};
/**
 * A route object represents a logical route, with (optionally) its child
 * routes organized in a tree-like structure.
 */
export interface RouteObject {
    caseSensitive?: boolean;
    children?: RouteObject[];
    element?: React.ReactNode;
    index?: boolean;
    path?: string;
}
/**
 * Returns a path with params interpolated.
 *
 * @see https://reactrouter.com/docs/en/v6/api#generatepath
 */
export declare function generatePath(path: string, params?: Params): string;
/**
 * A RouteMatch contains info about how a route matched a URL.
 */
export interface RouteMatch<ParamKey extends string = string> {
    /**
     * The names and values of dynamic parameters in the URL.
     */
    params: Params<ParamKey>;
    /**
     * The portion of the URL pathname that was matched.
     */
    pathname: string;
    /**
     * The portion of the URL pathname that was matched before child routes.
     */
    pathnameBase: string;
    /**
     * The route object that was used to match.
     */
    route: RouteObject;
}
/**
 * Matches the given routes to a location and returns the match data.
 *
 * @see https://reactrouter.com/docs/en/v6/api#matchroutes
 */
export declare function matchRoutes(routes: RouteObject[], locationArg: Partial<Location> | string, basename?: string): RouteMatch[] | null;
/**
 * A PathPattern is used to match on some portion of a URL pathname.
 */
export interface PathPattern<Path extends string = string> {
    /**
     * A string to match against a URL pathname. May contain `:id`-style segments
     * to indicate placeholders for dynamic parameters. May also end with `/*` to
     * indicate matching the rest of the URL pathname.
     */
    path: Path;
    /**
     * Should be `true` if the static portions of the `path` should be matched in
     * the same case.
     */
    caseSensitive?: boolean;
    /**
     * Should be `true` if this pattern should match the entire URL pathname.
     */
    end?: boolean;
}
/**
 * A PathMatch contains info about how a PathPattern matched on a URL pathname.
 */
export interface PathMatch<ParamKey extends string = string> {
    /**
     * The names and values of dynamic parameters in the URL.
     */
    params: Params<ParamKey>;
    /**
     * The portion of the URL pathname that was matched.
     */
    pathname: string;
    /**
     * The portion of the URL pathname that was matched before child routes.
     */
    pathnameBase: string;
    /**
     * The pattern that was used to match.
     */
    pattern: PathPattern;
}
/**
 * Performs pattern matching on a URL pathname and returns information about
 * the match.
 *
 * @see https://reactrouter.com/docs/en/v6/api#matchpath
 */
export declare function matchPath<ParamKey extends ParamParseKey<Path>, Path extends string>(pattern: PathPattern<Path> | Path, pathname: string): PathMatch<ParamKey> | null;
/**
 * Returns a resolved path object relative to the given pathname.
 *
 * @see https://reactrouter.com/docs/en/v6/api#resolvepath
 */
export declare function resolvePath(to: To, fromPathname?: string): Path;
export declare function resolveTo(toArg: To, routePathnames: string[], locationPathname: string): Path;
export declare function getToPathname(to: To): string | undefined;
export declare function stripBasename(pathname: string, basename: string): string | null;
export declare const joinPaths: (paths: string[]) => string;
export declare const normalizePathname: (pathname: string) => string;
export {};
