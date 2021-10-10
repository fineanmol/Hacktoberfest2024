(function() {
    "use strict"

    function fibonacci(n) {
        if (n == 1) {
            return [ 1 ];
        }

        var fib = [ 1, 1 ];
        
        for (var i = 2; i < n; i++) {
            fib.push(fib[ i - 1 ] + fib[ i - 2 ]);
        }

        return fib;
    }

    module.exports = fibonacci;
})();
