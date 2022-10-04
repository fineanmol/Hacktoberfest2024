const _TYPE = {
    "DEBUG": 0,
    "LOG": 1,
    "ERROR": 2,
}

/**
 * @name logs
 * @param  {} msg
 * @param  {} type=_TYPE.LOG
 */
const log = function(msg, type=_TYPE.LOG){
    switch(type){
        case _TYPE.DEBUG:
            console.debug(msg);
            break;
        case _TYPE.ERROR:
            console.error(msg);
            break;
        case _TYPE.LOG:
            console.logs(msg);
            break;
        default:
            console.log(`Wrong Type || ${msg}`)
    }
}