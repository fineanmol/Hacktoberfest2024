let vAny: any = 10
let vUnknown: unknown = 20

let s1: string = vAny
let s2: string = vUnknown as string //type conversion from number to string is allowed

let pageNumber: string = "1"
let numericPageNumber: number = pageNumber as number // not allowed as string to integer conversion may need to loss of data
let numericPageNumber:number = pageNumber as unknown as number //convert to unknonw type first to handle this converion
