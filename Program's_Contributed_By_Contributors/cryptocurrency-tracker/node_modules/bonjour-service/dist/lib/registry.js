"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Registry = void 0;
const array_flatten_1 = __importDefault(require("array-flatten"));
const dns_equal_1 = __importDefault(require("dns-equal"));
const service_1 = __importDefault(require("./service"));
const REANNOUNCE_MAX_MS = 60 * 60 * 1000;
const REANNOUNCE_FACTOR = 3;
class Registry {
    constructor(server) {
        this.services = [];
        this.activated = false;
        this.server = server;
    }
    publish(config) {
        let service = new service_1.default(config);
        service.start = this.start.bind(service, this);
        service.stop = this.stop.bind(service, this);
        service.start({ probe: config.probe !== false });
        return service;
    }
    unpublishAll(callback) {
        this.teardown(this.server, this.services, callback);
        this.services = [];
    }
    destroy() {
        this.services.map(service => service.destroyed = true);
    }
    start(registry, opts) {
        if (this.activated)
            return;
        this.activated = true;
        registry.services.push(this);
        if (!(this instanceof service_1.default))
            return;
        if (opts.probe) {
            var service = this;
            registry.probe(registry.server.mdns, this, (exists) => {
                if (exists) {
                    service.stop();
                    console.log(new Error('Service name is already in use on the network'));
                    return;
                }
                registry.announce(registry.server, service);
            });
        }
        else {
            registry.announce(registry.server, this);
        }
    }
    stop(registry, callback) {
        if (!this.activated)
            return;
        if (!(this instanceof service_1.default))
            return;
        registry.teardown(registry.server, this, callback);
        var index = registry.services.indexOf(this);
        if (index !== -1)
            registry.services.splice(index, 1);
    }
    probe(mdns, service, callback) {
        var sent = false;
        var retries = 0;
        var timer;
        const send = () => {
            if (!service.activated || service.destroyed)
                return;
            mdns.query(service.fqdn, 'ANY', function () {
                sent = true;
                timer = setTimeout(++retries < 3 ? send : done, 250);
                timer.unref();
            });
        };
        const onresponse = (packet) => {
            if (!sent)
                return;
            if (packet.answers.some(matchRR) || packet.additionals.some(matchRR))
                done(true);
        };
        const matchRR = (rr) => {
            return (0, dns_equal_1.default)(rr.name, service.fqdn);
        };
        const done = (exists) => {
            mdns.removeListener('response', onresponse);
            clearTimeout(timer);
            callback(!!exists);
        };
        mdns.on('response', onresponse);
        setTimeout(send, Math.random() * 250);
    }
    announce(server, service) {
        var delay = 1000;
        var packet = service.records();
        server.register(packet);
        const broadcast = () => {
            if (!service.activated || service.destroyed)
                return;
            server.mdns.respond(packet, function () {
                if (!service.published) {
                    service.activated = true;
                    service.published = true;
                    service.emit('up');
                }
                delay = delay * REANNOUNCE_FACTOR;
                if (delay < REANNOUNCE_MAX_MS && !service.destroyed) {
                    setTimeout(broadcast, delay).unref();
                }
            });
        };
        broadcast();
    }
    teardown(server, services, callback) {
        if (!Array.isArray(services))
            services = [services];
        services = services.filter((service) => service.activated);
        var records = array_flatten_1.default.depth(services.map(function (service) {
            service.activated = false;
            var records = service.records();
            records.forEach((record) => {
                record.ttl = 0;
            });
            return records;
        }), 1);
        if (records.length === 0)
            return callback && callback();
        server.unregister(records);
        server.mdns.respond(records, function () {
            services.forEach(function (service) {
                service.published = false;
            });
            if (typeof callback === "function") {
                callback.apply(null, arguments);
            }
        });
    }
}
exports.Registry = Registry;
exports.default = Registry;
//# sourceMappingURL=registry.js.map