(function($){
    $.fn.menu = function(options){

        // settings
        var settings = $.extend(true, {}, {
            selector: this.selector,
            offcanvas: {
                style: false,
                canvas: '.menu-canvas',
                scroller: 'html',
                blur: false,
                blurfilter: false
            },
            expand: {
                enabled: false,
                button: true,
                label: '<span class="label">Open menu</span>',
                single: false,
                blur: false,
                blurfilter: false
            },
            oninit: false,
            beforetoggle: false,
            ontoggle: false,
            onexpand: false,
            destroy: false
        }, options);

        // menu
        this.each(function(){

            // get objects
            var menu = $(this);
            var buttons = $('[href="#' + menu.attr('id') + '"],[data-menu="' + menu.attr('id') + '"]');

            // destroy?
            if(settings.destroy){
                menu.trigger('menu-destroy');
            }

            // create
            else {

                // init
                menu.on('menu-init', function(){

                    // add classes
                    menu.addClass('ui-menu');

                    // off canvas?
                    if(settings.offcanvas.style){

                        // add classes
                        menu.addClass('ui-menu-offcanvas');
                        $(settings.offcanvas.canvas).addClass('ui-menu-canvas');

                        // no scrolling
                        $(settings.offcanvas.scroller).addClass('ui-menu-noscroll');

                        // blur?
                        if(settings.offcanvas.blur){

                            // blur sections on click
                            $(document).on('click', function(e){

                                // not in menu?
                                var targetfilter = '.ui-menu, .ui-menu *, .ui-menu-btn, .ui-menu-btn *' + (settings.offcanvas.blurfilter ? ', ' + settings.offcanvas.blurfilter : '');
                                if(!$(e.target).is(targetfilter)){
                                    $('.ui-menu-active').trigger('menu-toggle');
                                }

                            });

                        }

                    }

                    // buttons
                    buttons.each(function(){

                        // add classes
                        $(this).addClass('ui-menu-btn');

                        // add attributes
                        $(this).attr('aria-expanded', false);

                        // toggle on click
                        $(this).on('click', function(e){
                            e.preventDefault();

                            // toggle menu
                            menu.trigger('menu-toggle');

                        });

                    });

                    // expand?
                    if(settings.expand.enabled){

                        // find child menus
                        menu.find('ul ul').each(function(){

                            // add classes
                            var ul = $(this);
                            ul.addClass('ui-menu-section');

                            // expand buttons?
                            var button = false;
                            if(settings.expand.button){

                                // create toggle button
                                button = $('<button class="ui-menu-section-btn">' + settings.expand.label + '</button>');

                                // add button
                                ul.before(button);

                            }

                            // expand when clicking nav link
                            else{
                                button = ul.prev('a,button,span');
                            }

                            // expanded
                            button.attr('aria-expanded', false);

                            // click
                            button.on('click', function(e){
                                e.preventDefault();

                                // toggle classes
                                $(this).toggleClass('ui-menu-section-btn-active');
                                $(this).siblings('.ui-menu-section').toggleClass('ui-menu-section-active');

                                // toggle attributes
                                if($(this).hasClass('ui-menu-section-btn-active')){

                                    // expanded
                                    $(this).attr('aria-expanded', true);

                                    // close sibling menus
                                    if(settings.expand.single){
                                        ul.closest('li').siblings('li').find('.ui-menu-section-btn-active').trigger('click');
                                    }

                                }
                                else{
                                    $(this).attr('aria-expanded', false);
                                }

                                // onexpand?
                                if(typeof(settings.onexpand) == 'function'){
                                    settings.onexpand(button);
                                }

                            });

                        });

                        // blur?
                        if(settings.expand.blur){

                            // blur sections on click
                            $(document).on('click', function(e){

                                // not menu?
                                var targetfilter = '.ui-menu, .ui-menu *, .ui-menu-btn, .ui-menu-btn *' + (settings.expand.blurfilter ? ', ' + settings.expand.blurfilter : '');
                                if(!$(e.target).is(targetfilter)){
                                    $('.ui-menu-section-btn-active').trigger('click');
                                }

                            });

                        }

                    }

                    // oninit?
                    if(typeof(settings.oninit) == 'function'){
                        settings.oninit(menu);
                    }

                });

                // toggle
                menu.on('menu-toggle', function(){

                    // beforetoggle?
                    if(typeof(settings.beforetoggle) == 'function'){
                        settings.beforetoggle(menu);
                    }

                    // toggle classes
                    menu.toggleClass('ui-menu-active');

                    // off-canvas?
                    if(settings.offcanvas.style){
                        $(settings.offcanvas.canvas).toggleClass('ui-menu-canvas-active-' + settings.offcanvas.style);
                        $(settings.offcanvas.scroller).toggleClass('ui-menu-noscroll-active');
                    }

                    // active?
                    var active = menu.hasClass('ui-menu-active');

                    // expanded
                    buttons.each(function(){

                        // toggle classes
                        $(this).toggleClass('ui-menu-btn-active');

                        // expanded?
                        if(active){
                            $(this).attr('aria-expanded', true);
                        }
                        else{
                            $(this).attr('aria-expanded', false);
                        }

                    });

                    // ontoggle?
                    if(typeof(settings.ontoggle) == 'function'){
                        settings.ontoggle(menu, active);
                    }

                });

                // destroy
                menu.on('menu-destroy', function(){

                    // remove classes
                    menu.removeClass('ui-menu ui-menu-offcanvas ui-menu-active');
                    $(settings.offcanvas.scroller).removeClass('ui-menu-noscroll ui-menu-noscroll-active');
                    $(settings.offcanvas.canvas).removeClass('ui-menu-canvas').removeClass(function(i, css){
                        return(css.match(/\bui-menu-canvas-active-\S+/g) || []).join(' ');
                    });

                    // buttons
                    buttons.each(function(){

                        // remove classes
                        $(this).removeClass('ui-menu-btn ui-menu-btn-active');

                        // remove attributes
                        $(this).removeAttr('aria-expanded');

                        // remove click
                        $(this).off('click');

                    });

                    // remove expand
                    menu.find('ul ul').removeClass('ui-menu-section ui-menu-section-active');
                    menu.find('.ui-menu-section-btn').remove();

                    // destroy events
                    menu.off('menu-init menu-toggle menu-destroy');
                    $(document).off('click');

                });

                // init
                menu.trigger('menu-init');

            }

        });

        // done
        return this;

    };
}(jQuery));
