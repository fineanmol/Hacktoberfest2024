/**
 * jQuery Mapify v1.0
 * http://github.com/castlegateit/jquery-mapify
 *
 * Copyright (c) 2016 Castlegate IT
 * http://www.castlegateit.co.uk/
 *
 * Released under the MIT License
 * http://www.opensource.org/licenses/MIT
 */
;(function($) {
    'use strict';

    // Resize timer
    var resizeDone = false;

    // Has the map zoom been set?
    var zoomSet = false;

    // Has the Google Maps API started loading?
    var googleLoading = false;

    // Has the Google Maps API already loaded?
    var googleLoaded = function() {
        if (
            typeof google === 'undefined' ||
            typeof google.maps === 'undefined'
        ) {
            return false;
        }

        return true;
    };

    // Wait for a condition before doing something, with options for time
    // intervals and time limit.
    var waitFor = function(condition, callback, time, stop) {
        if (condition()) {
            return callback();
        }

        time = time || 100;
        stop = stop || false;

        var interval = setInterval(function() {
            if (condition()) {
                callback();
                clearInterval(interval);
            }
        }, time);

        if (stop) {
            var timeout = setTimeout(function() {
                clearInterval(interval);
            }, stop);
        }
    };

    // Return a valid map type based on a string or map type ID. If the supplied
    // map type is invalid, return the default ROADMAP map type.
    var mapType = function(key) {
        var types = google.maps.MapTypeId;

        // If string is an array key, check for key in array of types
        if (types.hasOwnProperty(key)) {
            return types[key];
        }

        // If string is an array value, check for value in array of types
        for (var type in types) {
            if (types[type] === key) {
                return key;
            }
        }

        // Return default type
        return types.ROADMAP;
    };

    // Fit map to bounds and set map center and zoom
    var resetBounds = function(map, bounds, center, zoom) {
        map.fitBounds(bounds);

        // Set map center
        if (
            center.hasOwnProperty('lat') &&
            center.hasOwnProperty('lng')
        ) {
            map.addListener('bounds_changed', function() {
                map.setCenter(center);
            });
        }

        // Set map zoom. The bounds_changed event is triggered by the user
        // manually changing the zoom level, so this should only run once.
        if (zoom) {
            map.addListener('bounds_changed', function() {
                if (zoomSet) {
                    return;
                }

                map.setZoom(zoom);
                zoomSet = true;
            });
        }
    };

    // Add map to element
    var mapifyElement = function(element, settings) {
        var map = new google.maps.Map(element, {
            mapTypeId: mapType(settings.type)
        });
        var bounds = new google.maps.LatLngBounds();

        // Add points to the map
        $.each(settings.points, function(i, point) {
            var position;
            var marker;
            var infoWindow;

            // At the very least, a point needs latitude and longitude
            // values.
            if (
                !point.hasOwnProperty('lat') ||
                !point.hasOwnProperty('lng')
            ) {
                return false;
            }

            position = new google.maps.LatLng({
                lat: point.lat,
                lng: point.lng
            });

            // Add marker to map
            if (point.marker) {
                marker = new google.maps.Marker({
                    map: map,
                    position: position
                });

                // If marker option is a string, assume this is a custom
                // marker image.
                if (typeof point.marker === 'string') {
                    marker.setIcon(point.marker);
                }

                // Add marker title (optional)
                if (point.title) {
                    marker.setTitle(point.title);
                }

                // Add information window (optional)
                if (point.infoWindow) {
                    infoWindow = new google.maps.InfoWindow({
                        content: point.infoWindow
                    });

                    marker.addListener('click', function() {
                        infoWindow.open(map, marker);
                    });
                }
            }

            // Extend bounds
            bounds.extend(position);
        });

        // Set map position and zoom based on the points and settings
        resetBounds(map, bounds, settings.center, settings.zoom);

        if (settings.responsive) {
            $(window).on('resizeDone', function() {
                zoomSet = false;
                resetBounds(map, bounds, settings.center, settings.zoom);
            });
        }

        // Run callback
        if (settings.callback) {
            settings.callback(map, bounds, settings);
        }
    };

    // Add map when Google Maps API is ready
    var mapify = function(collection, settings) {
        waitFor(googleLoaded, function() {
            collection.each(function(i, element) {
                mapifyElement(element, settings);
            });
        }, 50, 4000);
    };

    // Add method to jQuery
    $.fn.mapify = function(options) {
        var collection = this;
        var settings = $.extend({
            points: [],
            type: 'roadmap',
            center: false,
            zoom: false,
            responsive: false,
            callback: false
        }, options);

        // If the API has not been loaded and script loader has not been run,
        // load the Google Maps API script.
        if (!googleLoaded || !googleLoading) {
            googleLoading = true;

            $.getScript('https://maps.google.com/maps/api/js?language=en', function() {
                mapify(collection, settings);
            });
        } else {
            mapify(collection, settings);
        }
    };

    // Trigger resizeDone event when window resize complete
    $(window).on('resize', function() {
        clearTimeout(resizeDone);

        resizeDone = setTimeout(function() {
            $(window).trigger('resizeDone');
        }, 100);
    });
})(jQuery);
