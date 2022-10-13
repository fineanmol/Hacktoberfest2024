"use strict";
/*--------------------------------------------------------------------------

TypeBox: JSON Schema Type Builder with Static Type Resolution for TypeScript

The MIT License (MIT)

Copyright (c) 2021 Haydn Paterson (sinclair) <haydn.developer@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

---------------------------------------------------------------------------*/
Object.defineProperty(exports, "__esModule", { value: true });
exports.Type = exports.TypeBuilder = exports.VoidKind = exports.UndefinedKind = exports.PromiseKind = exports.FunctionKind = exports.ConstructorKind = exports.RefKind = exports.AnyKind = exports.UnknownKind = exports.NullKind = exports.BooleanKind = exports.IntegerKind = exports.NumberKind = exports.StringKind = exports.LiteralKind = exports.EnumKind = exports.ArrayKind = exports.RecordKind = exports.ObjectKind = exports.TupleKind = exports.UnionKind = exports.IntersectKind = exports.KeyOfKind = exports.NamespaceKind = exports.ReadonlyModifier = exports.OptionalModifier = exports.ReadonlyOptionalModifier = void 0;
// --------------------------------------------------------------------------
// Modifiers
// --------------------------------------------------------------------------
exports.ReadonlyOptionalModifier = Symbol('ReadonlyOptionalModifier');
exports.OptionalModifier = Symbol('OptionalModifier');
exports.ReadonlyModifier = Symbol('ReadonlyModifier');
// --------------------------------------------------------------------------
// Schema Standard
// --------------------------------------------------------------------------
exports.NamespaceKind = Symbol('NamespaceKind');
exports.KeyOfKind = Symbol('KeyOfKind');
exports.IntersectKind = Symbol('IntersectKind');
exports.UnionKind = Symbol('UnionKind');
exports.TupleKind = Symbol('TupleKind');
exports.ObjectKind = Symbol('ObjectKind');
exports.RecordKind = Symbol('RecordKind');
exports.ArrayKind = Symbol('ArrayKind');
exports.EnumKind = Symbol('EnumKind');
exports.LiteralKind = Symbol('LiteralKind');
exports.StringKind = Symbol('StringKind');
exports.NumberKind = Symbol('NumberKind');
exports.IntegerKind = Symbol('IntegerKind');
exports.BooleanKind = Symbol('BooleanKind');
exports.NullKind = Symbol('NullKind');
exports.UnknownKind = Symbol('UnknownKind');
exports.AnyKind = Symbol('AnyKind');
exports.RefKind = Symbol('RefKind');
// --------------------------------------------------------------------------
// Extended Schema Types
// --------------------------------------------------------------------------
exports.ConstructorKind = Symbol('ConstructorKind');
exports.FunctionKind = Symbol('FunctionKind');
exports.PromiseKind = Symbol('PromiseKind');
exports.UndefinedKind = Symbol('UndefinedKind');
exports.VoidKind = Symbol('VoidKind');
// --------------------------------------------------------------------------
// Utility
// --------------------------------------------------------------------------
function isObject(object) {
    return typeof object === 'object' && object !== null && !Array.isArray(object);
}
function isArray(object) {
    return typeof object === 'object' && object !== null && Array.isArray(object);
}
function clone(object) {
    if (isObject(object))
        return Object.keys(object).reduce((acc, key) => ({ ...acc, [key]: clone(object[key]) }), {});
    if (isArray(object))
        return object.map((item) => clone(item));
    return object;
}
// --------------------------------------------------------------------------
// TypeBuilder
// --------------------------------------------------------------------------
class TypeBuilder {
    schemas;
    constructor() {
        this.schemas = new Map();
    }
    /** `Standard` Modifies an object property to be both readonly and optional */
    ReadonlyOptional(item) {
        return { ...item, modifier: exports.ReadonlyOptionalModifier };
    }
    /** `Standard` Modifies an object property to be readonly */
    Readonly(item) {
        return { ...item, modifier: exports.ReadonlyModifier };
    }
    /** `Standard` Modifies an object property to be optional */
    Optional(item) {
        return { ...item, modifier: exports.OptionalModifier };
    }
    /** `Standard` Creates a type type */
    Tuple(items, options = {}) {
        const additionalItems = false;
        const minItems = items.length;
        const maxItems = items.length;
        const schema = ((items.length > 0)
            ? { ...options, kind: exports.TupleKind, type: 'array', items, additionalItems, minItems, maxItems }
            : { ...options, kind: exports.TupleKind, type: 'array', minItems, maxItems });
        return this.Store(schema);
    }
    /** `Standard` Creates an object type with the given properties */
    Object(properties, options = {}) {
        const property_names = Object.keys(properties);
        const optional = property_names.filter(name => {
            const candidate = properties[name];
            return (candidate.modifier &&
                (candidate.modifier === exports.OptionalModifier ||
                    candidate.modifier === exports.ReadonlyOptionalModifier));
        });
        const required_names = property_names.filter(name => !optional.includes(name));
        const required = (required_names.length > 0) ? required_names : undefined;
        return this.Store(((required)
            ? { ...options, kind: exports.ObjectKind, type: 'object', properties, required }
            : { ...options, kind: exports.ObjectKind, type: 'object', properties }));
    }
    /** `Standard` Creates an intersect type. */
    Intersect(items, options = {}) {
        return this.Store({ ...options, kind: exports.IntersectKind, type: 'object', allOf: items });
    }
    /** `Standard` Creates a union type */
    Union(items, options = {}) {
        return this.Store({ ...options, kind: exports.UnionKind, anyOf: items });
    }
    /** `Standard` Creates an array type */
    Array(items, options = {}) {
        return this.Store({ ...options, kind: exports.ArrayKind, type: 'array', items });
    }
    /** `Standard` Creates an enum type from a TypeScript enum */
    Enum(item, options = {}) {
        const values = Object.keys(item).filter(key => isNaN(key)).map(key => item[key]);
        const anyOf = values.map(value => typeof value === 'string' ? { type: 'string', const: value } : { type: 'number', const: value });
        return this.Store({ ...options, kind: exports.EnumKind, anyOf });
    }
    /** `Standard` Creates a literal type. Supports string, number and boolean values only */
    Literal(value, options = {}) {
        return this.Store({ ...options, kind: exports.LiteralKind, const: value, type: typeof value });
    }
    /** `Standard` Creates a string type */
    String(options = {}) {
        return this.Store({ ...options, kind: exports.StringKind, type: 'string' });
    }
    /** `Standard` Creates a string type from a regular expression */
    RegEx(regex, options = {}) {
        return this.String({ ...options, pattern: regex.source });
    }
    /** `Standard` Creates a number type */
    Number(options = {}) {
        return this.Store({ ...options, kind: exports.NumberKind, type: 'number' });
    }
    /** `Standard` Creates an integer type */
    Integer(options = {}) {
        return this.Store({ ...options, kind: exports.IntegerKind, type: 'integer' });
    }
    /** `Standard` Creates a boolean type */
    Boolean(options = {}) {
        return this.Store({ ...options, kind: exports.BooleanKind, type: 'boolean' });
    }
    /** `Standard` Creates a null type */
    Null(options = {}) {
        return this.Store({ ...options, kind: exports.NullKind, type: 'null' });
    }
    /** `Standard` Creates an unknown type */
    Unknown(options = {}) {
        return this.Store({ ...options, kind: exports.UnknownKind });
    }
    /** `Standard` Creates an any type */
    Any(options = {}) {
        return this.Store({ ...options, kind: exports.AnyKind });
    }
    /** `Standard` Creates a record type */
    Record(key, value, options = {}) {
        const pattern = (() => {
            switch (key.kind) {
                case exports.UnionKind: return `^${key.anyOf.map((literal) => literal.const).join('|')}$`;
                case exports.KeyOfKind: return `^${key.enum.join('|')}$`;
                case exports.NumberKind: return '^(0|[1-9][0-9]*)$';
                case exports.StringKind: return key.pattern ? key.pattern : '^.*$';
                default: throw Error('Invalid Record Key');
            }
        })();
        return this.Store({ ...options, kind: exports.RecordKind, type: 'object', patternProperties: { [pattern]: value } });
    }
    /** `Standard` Creates a keyof type from the given object */
    KeyOf(object, options = {}) {
        const source = this.Deref(object);
        const keys = Object.keys(source.properties);
        return this.Store({ ...options, kind: exports.KeyOfKind, type: 'string', enum: keys });
    }
    /** `Standard` Makes all properties in the given object type required */
    Required(object, options = {}) {
        const source = this.Deref(object);
        const schema = { ...clone(source), ...options };
        schema.required = Object.keys(schema.properties);
        for (const key of Object.keys(schema.properties)) {
            const property = schema.properties[key];
            switch (property.modifier) {
                case exports.ReadonlyOptionalModifier:
                    property.modifier = exports.ReadonlyModifier;
                    break;
                case exports.ReadonlyModifier:
                    property.modifier = exports.ReadonlyModifier;
                    break;
                case exports.OptionalModifier:
                    delete property.modifier;
                    break;
                default:
                    delete property.modifier;
                    break;
            }
        }
        return this.Store(schema);
    }
    /** `Standard` Makes all properties in the given object type optional */
    Partial(object, options = {}) {
        const source = this.Deref(object);
        const schema = { ...clone(source), ...options };
        delete schema.required;
        for (const key of Object.keys(schema.properties)) {
            const property = schema.properties[key];
            switch (property.modifier) {
                case exports.ReadonlyOptionalModifier:
                    property.modifier = exports.ReadonlyOptionalModifier;
                    break;
                case exports.ReadonlyModifier:
                    property.modifier = exports.ReadonlyOptionalModifier;
                    break;
                case exports.OptionalModifier:
                    property.modifier = exports.OptionalModifier;
                    break;
                default:
                    property.modifier = exports.OptionalModifier;
                    break;
            }
        }
        return this.Store(schema);
    }
    /** `Standard` Picks property keys from the given object type */
    Pick(object, keys, options = {}) {
        const source = this.Deref(object);
        const schema = { ...clone(source), ...options };
        schema.required = schema.required ? schema.required.filter((key) => keys.includes(key)) : undefined;
        for (const key of Object.keys(schema.properties)) {
            if (!keys.includes(key))
                delete schema.properties[key];
        }
        return this.Store(schema);
    }
    /** `Standard` Omits property keys from the given object type */
    Omit(object, keys, options = {}) {
        const source = this.Deref(object);
        const schema = { ...clone(source), ...options };
        schema.required = schema.required ? schema.required.filter((key) => !keys.includes(key)) : undefined;
        for (const key of Object.keys(schema.properties)) {
            if (keys.includes(key))
                delete schema.properties[key];
        }
        return this.Store(schema);
    }
    /** `Standard` Omits the `kind` and `modifier` properties from the underlying schema */
    Strict(schema, options = {}) {
        return JSON.parse(JSON.stringify({ ...options, ...schema }));
    }
    /** `Extended` Creates a constructor type */
    Constructor(args, returns, options = {}) {
        return this.Store({ ...options, kind: exports.ConstructorKind, type: 'constructor', arguments: args, returns });
    }
    /** `Extended` Creates a function type */
    Function(args, returns, options = {}) {
        return this.Store({ ...options, kind: exports.FunctionKind, type: 'function', arguments: args, returns });
    }
    /** `Extended` Creates a promise type */
    Promise(item, options = {}) {
        return this.Store({ ...options, type: 'promise', kind: exports.PromiseKind, item });
    }
    /** `Extended` Creates a undefined type */
    Undefined(options = {}) {
        return this.Store({ ...options, type: 'undefined', kind: exports.UndefinedKind });
    }
    /** `Extended` Creates a void type */
    Void(options = {}) {
        return this.Store({ ...options, type: 'void', kind: exports.VoidKind });
    }
    /** `Standard` Creates a namespace for a set of related types */
    Namespace($defs, options = {}) {
        return this.Store({ ...options, kind: exports.NamespaceKind, $defs });
    }
    Ref(...args) {
        if (args.length === 2) {
            const namespace = args[0];
            const targetKey = args[1];
            if (namespace.$id === undefined)
                throw new Error(`Referenced namespace has no $id`);
            if (!this.schemas.has(namespace.$id))
                throw new Error(`Unable to locate namespace with $id '${namespace.$id}'`);
            return this.Store({ kind: exports.RefKind, $ref: `${namespace.$id}#/$defs/${targetKey}` });
        }
        else if (args.length === 1) {
            const target = args[0];
            if (target.$id === undefined)
                throw new Error(`Referenced schema has no $id`);
            if (!this.schemas.has(target.$id))
                throw new Error(`Unable to locate schema with $id '${target.$id}'`);
            return this.Store({ kind: exports.RefKind, $ref: target.$id });
        }
        else {
            throw new Error('Type.Ref: Invalid arguments');
        }
    }
    /** `Experimental` Creates a recursive type */
    Rec(callback, options = {}) {
        const $id = options.$id || '';
        const self = callback({ $ref: `${$id}#/$defs/self` });
        return this.Store({ ...options, $ref: `${$id}#/$defs/self`, $defs: { self } });
    }
    /** Conditionally stores and schema if it contains an $id and returns  */
    Store(schema) {
        const $schema = schema;
        if (!$schema['$id'])
            return $schema;
        this.schemas.set($schema['$id'], $schema);
        return $schema;
    }
    /** Conditionally dereferences a schema if RefKind. Otherwise return argument */
    Deref(schema) {
        const $schema = schema;
        if ($schema['kind'] !== exports.RefKind)
            return schema;
        if (!this.schemas.has($schema['$ref']))
            throw Error(`Unable to locate schema with $id '${$schema['$ref']}'`);
        return this.Deref(this.schemas.get($schema['$ref']));
    }
}
exports.TypeBuilder = TypeBuilder;
exports.Type = new TypeBuilder();
