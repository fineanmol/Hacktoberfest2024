# vanilla-swipe

Tiny vanilla JS library to detect swipe direction.

[![Build Status](https://travis-ci.com/maxmarinich/vanilla-swipe.svg?branch=master)](https://travis-ci.com/maxmarinich/vanilla-swipe)
[![npm version](https://badge.fury.io/js/vanilla-swipe.svg)](https://img.shields.io/badge/coverage-100%25-brightgreen)
[![covarage](https://img.shields.io/badge/coverage-100%25-brightgreen)](https://img.shields.io/badge/coverage-100%25-brightgreen)

#### 👉 Live [demo](https://maxmarinich.github.io/vanilla-swipe).

### Types

```typescript
type ConstructorProps = {
  element?: HTMLElement | null;
  target?: HTMLElement | null;
  delta?: number | 10;
  directionDelta?: number | 0;
  rotationAngle?: number | 0;
  mouseTrackingEnabled?: boolean | false;
  touchTrackingEnabled?: boolean | true;
  preventDefaultTouchmoveEvent?: boolean | false;
  preventTrackingOnMouseleave?: boolean | false;
  onSwipeStart?: EventHandler;
  onSwiping?: EventHandler;
  onSwiped?: EventHandler;
  onTap?: EventHandler;
};

type EventHandler = {
  (e: Event, data: EventData): void;
};

type EventData = {
  absX: number;
  absY: number;
  deltaX: number;
  deltaY: number;
  directionX: 'LEFT' | 'RIGHT' | 'NONE';
  directionY: 'TOP' | 'BOTTOM' | 'NONE';
  duration: number; // ms
  velocity: number; // (px/ms)
};

```
### _Props_

- `element` - target event trigger
- `target` - additionally target event trigger, if specified  with the element, will be used by all handlers to trigger the action
- `delta` - minimal distance in `px` before a swipe starts
- `directionDelta` - minimum distance in `px` required for the direction to be reversed while swiping. 
- `rotationAngle` - rotation angle
- `mouseTrackingEnabled` - enable mouse tracking
- `touchTrackingEnabled` - enable touch tracking
- `preventDefaultTouchmoveEvent` - prevent default touch events while touching
- `preventTrackingOnMouseleave` - triggered `onSwiped` callback when the event loses the element's focus
- `onSwipeStart` - triggered on swipe start (if the `delta` is passed)
- `onSwiping` - triggered during swipe
- `onSwiped` - triggered after swipe
- `onTap` - triggered when the swipe value is less than the minimum distance (`delta`)

### _Methods_

- `init(): void`
- `update(options: ConstructorProps): void`
- `destroy(): void`
- static `isTouchEventsSupported(): boolean`

### _Install_

```bash
npm install vanilla-swipe
```

### _Examples_

```js
import VanillaSwipe from 'vanilla-swipe';

const isTouchEventsSupported = VanillaSwipe.isTouchEventsSupported();

const VS = new VanillaSwipe({
  element: document.getElementById('some-id'),
  onSwiping: handler,
  onSwiped: handler,
  mouseTrackingEnabled: true,
});

VS.init();

function handler() {
  console.log(...arguments); // -> Event, EventData
}
```

### Run project
```$xslt
npm i
npm start
```

### _Tests_

```
npm test
```

### _Coverage_

```
npm run test:coverage
```
