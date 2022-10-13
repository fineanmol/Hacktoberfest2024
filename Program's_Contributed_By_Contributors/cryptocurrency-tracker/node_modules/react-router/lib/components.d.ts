import * as React from "react";
import type { InitialEntry, Location, To } from "history";
import { Action as NavigationType } from "history";
import { Navigator } from "./context";
import type { RouteMatch, RouteObject } from "./router";
export interface MemoryRouterProps {
    basename?: string;
    children?: React.ReactNode;
    initialEntries?: InitialEntry[];
    initialIndex?: number;
}
/**
 * A <Router> that stores all entries in memory.
 *
 * @see https://reactrouter.com/docs/en/v6/api#memoryrouter
 */
export declare function MemoryRouter({ basename, children, initialEntries, initialIndex, }: MemoryRouterProps): React.ReactElement;
export interface NavigateProps {
    to: To;
    replace?: boolean;
    state?: any;
}
/**
 * Changes the current location.
 *
 * Note: This API is mostly useful in React.Component subclasses that are not
 * able to use hooks. In functional components, we recommend you use the
 * `useNavigate` hook instead.
 *
 * @see https://reactrouter.com/docs/en/v6/api#navigate
 */
export declare function Navigate({ to, replace, state }: NavigateProps): null;
export interface OutletProps {
    context?: unknown;
}
/**
 * Renders the child route's element, if there is one.
 *
 * @see https://reactrouter.com/docs/en/v6/api#outlet
 */
export declare function Outlet(props: OutletProps): React.ReactElement | null;
export interface RouteProps {
    caseSensitive?: boolean;
    children?: React.ReactNode;
    element?: React.ReactNode | null;
    index?: boolean;
    path?: string;
}
export interface PathRouteProps {
    caseSensitive?: boolean;
    children?: React.ReactNode;
    element?: React.ReactNode | null;
    index?: false;
    path: string;
}
export interface LayoutRouteProps {
    children?: React.ReactNode;
    element?: React.ReactNode | null;
}
export interface IndexRouteProps {
    element?: React.ReactNode | null;
    index: true;
}
/**
 * Declares an element that should be rendered at a certain URL path.
 *
 * @see https://reactrouter.com/docs/en/v6/api#route
 */
export declare function Route(_props: PathRouteProps | LayoutRouteProps | IndexRouteProps): React.ReactElement | null;
export interface RouterProps {
    basename?: string;
    children?: React.ReactNode;
    location: Partial<Location> | string;
    navigationType?: NavigationType;
    navigator: Navigator;
    static?: boolean;
}
/**
 * Provides location context for the rest of the app.
 *
 * Note: You usually won't render a <Router> directly. Instead, you'll render a
 * router that is more specific to your environment such as a <BrowserRouter>
 * in web browsers or a <StaticRouter> for server rendering.
 *
 * @see https://reactrouter.com/docs/en/v6/api#router
 */
export declare function Router({ basename: basenameProp, children, location: locationProp, navigationType, navigator, static: staticProp, }: RouterProps): React.ReactElement | null;
export interface RoutesProps {
    children?: React.ReactNode;
    location?: Partial<Location> | string;
}
/**
 * A container for a nested tree of <Route> elements that renders the branch
 * that best matches the current location.
 *
 * @see https://reactrouter.com/docs/en/v6/api#routes
 */
export declare function Routes({ children, location, }: RoutesProps): React.ReactElement | null;
/**
 * Creates a route config from a React "children" object, which is usually
 * either a `<Route>` element or an array of them. Used internally by
 * `<Routes>` to create a route config from its children.
 *
 * @see https://reactrouter.com/docs/en/v6/api#createroutesfromchildren
 */
export declare function createRoutesFromChildren(children: React.ReactNode): RouteObject[];
/**
 * Renders the result of `matchRoutes()` into a React element.
 */
export declare function renderMatches(matches: RouteMatch[] | null): React.ReactElement | null;
