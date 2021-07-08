const base64 = require('base-64');
const CryptoJS = require("crypto-js");

const header = {
    "sub": "1234567890",
    "name": "John Doe",
    "admin": true
}

const payload = {
    name: "Artur",
    surname: "Aghajanyan"
}
const encodedHeader = base64.encode(JSON.stringify(header));
const encodedPayload = base64.encode(JSON.stringify(payload));

const data = [encodedHeader, encodedPayload];

let res = CryptoJS.AES.encrypt(JSON.stringify(data), '1').toString();
console.log(encodedHeader);
console.log(encodedPayload);
console.log(res);
