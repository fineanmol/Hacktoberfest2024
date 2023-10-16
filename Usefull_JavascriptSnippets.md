
9 useful code snippets for everyday JavaScript development
#
javascript
#
webdev
#
tutorial
#
programming
Hello Everyone!

Welcome to this JavaScript snippets post, In this post we will look at some of the most common JavaScript snippets which will help you with your everyday JavaScript development.

You can always use 3rd party utility libraries, but knowing these vanilla JavaScript snippets is always beneficial.

And these snippets are so easy and small, that you should always prefer them instead of a 3rd party utility library.

This series is divided in 2 parts, this post is the first one.

Link to second post: Part 2 of this post

Now, let's get started.

1. HTTPS Redirect

Redirect HTTP protocol to HTTPS protocol.
const httpsRedirect = () => {
  if (location.protocol !== 'https:')
    location.replace('https://' + location.href.split('//')[1]);
};

httpsRedirect();
// Redirect from http://mydomain.com to https://mydomain.com
First we find out the protoco with window.location.protocol.
Then, if protocol is HTTP, we replace the URL with HTTPS protocol.
And, reload the page.
Note: Going back via brower's back button won't go to http, as it is replaced in the history.

2. Input value as a Number

Ever wanted an input value as Number and not string? By default we always get input value from JS as string. Then we convert it to Number.

The purpose of the number type is that mobile browsers use this for showing the right keyboards and some browsers use this for validation purposes. For example the email type will show a keyboard with the @ and '.' on the keyboard and number will show a numeric keyboard.

But, there is a better way to get the input value as Number.
const numInput = document.getElementById('num-input');

let num;
// Bad: parseFloat() converts the string to a number
num = parseFloat(numInput.value);

// Good: returns a numeric value
num = numInput.valueAsNumber;
HTMLInputElement.valueAsNumber returns a numeric value or NaN from the input value.

3. Handle Click Outside

If you want to do something when user clicks outside of the specified element, this snippet is going to save your day.
const onClickOutside = (elementId, callback) => {
  const element = document.getElementById(elementId);

  document.addEventListener("click", (e) => {
    if (!element.contains(e.target)) callback();
  });
};

onClickOutside("red-box", () => console.log("Clicked outside red box"));

document.addEventListener("DOMContentLoaded", onClickOutside);
// Will log 'Hello' whenever the user clicks outside of #my-element
addEventListener is being used to listen to the click event.
Node.contains() check if the clicked element is outside of the specified element.
DOMContentLoaded event listener makes sure that the onClickOutside function is invoked only after HTML is mounted on the DOM.
4. Handle Scroll Stop

Maybe, there is something you want to do, when user stops scrolling. Here is a snippet to help you with that.
const onScrollStop = callback => {
  let isScrolling;
  window.addEventListener(
    'scroll',
    e => {
      clearTimeout(isScrolling);
      isScrolling = setTimeout(() => {
        callback();
      }, 150);
    },
    false
  );
};

onScrollStop(() => {
  console.log('The user has stopped scrolling');
});
addEventListener is used to listen to the scroll event.
Use setTimeout to wait for 150ms before invoking the callback.
clearTimeout is used to clear the timeout, if new scroll event is fired under 150ms.
5. Detect if CapsLock is on

Check if user's CapsLock is on or off.
// Assume, el is an input element, and msg is a p tag to show message.

el.addEventListener('keyup', e => {
  msg.style = e.getModifierState('CapsLock')
    ? 'display: block'
    : 'display: none';
});
KeyboardEvent.getModifierState() is used to determine the state of the CapsLock key on users keyboard.
So, that is it for this post. If you anyhow liked this post, make sure to show your support.


Thank You!

