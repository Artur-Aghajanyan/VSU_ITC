

const headers = {
    "alg": "HS256",
    "typ": "JWT"
  };

const payload = {
    "sub": "1234567890",
    "name": "John Doe",
    "admin": true
  };
 
const jwt = SHA256(
    base64UrlEncode(header) + "." +
    base64UrlEncode(payload),
    secret);

console.log(jwt);