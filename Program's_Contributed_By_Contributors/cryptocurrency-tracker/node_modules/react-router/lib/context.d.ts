import * as React from "react";
import type { History, Location } from "history";
import { Action as NavigationType } from "history";
import type { RouteMatch } from "./router";
/**
 * A Navigator is a "location changer"; it's how you get to different locations.
 *
 * Every history instance conforms to the Navigator interface, but the
 * distinction is useful primarily when it comes to the low-level <Router> API
 * where both the location and a navigator must be provided separately in order
 * to avoid "tearing" that may occur in a suspense-enabled app if the action
 * and/or location were to be read directly from the history instance.
 */
export declare type Navigator = Pick<History, "go" | "push" | "replace" | "createHref">;
interface NavigationContextObject {
    basename: string;
    navigator: Navigator;
    static: boolean;
}
export declare const NavigationContext: React.Context<NavigationContextObject>;
interface LocationContextObject {
    location: Location;
    navigationType: NavigationType;
}
export declare const LocationContext: React.Context<LocationContextObject>;
interface RouteContextObject {
    outlet: React.ReactElement | null;
    matches: RouteMatch[];
}
export declare const RouteContext: React.Context<RouteContextObject>;
export {};
