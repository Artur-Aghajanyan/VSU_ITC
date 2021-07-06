const {createHmac} = require('crypto');

const secret = 'abcdefg';

const HEADER = {
    "alg": "HS256",
    "typ": "JWT"
}

const PAYLOAD = {
    "sub": "1234567890",
    "name": "Den Smith",
    "admin": true
}

let headerCode = Buffer.from(JSON.stringify(HEADER)).toString('base64');
let payloadCode = Buffer.from(JSON.stringify(PAYLOAD)).toString('base64');

let hash = createHmac('sha256', secret)
    .update(headerCode + "." + payloadCode)
    .digest('hex');

hash = Buffer.from(JSON.stringify(hash)).toString('base64');

const code = headerCode + "." + payloadCode + "." + hash;
console.log(code)
