var  crypto = require('crypto');

var header = {
	"alg": "HS256",
	"type": "JWT"
}

var playload = {
	"sub": "1234567890",
	"name": "John Doe",
	"admin": true
};

let header_stringify = JSON.stringify(header);
let header_B64 = Buffer.from(header_stringify ).toString('Base64');

let playload_stringify = JSON.stringify(playload);
let playload_B64 = Buffer.from(playload_stringify ).toString('Base64');

let data = header_B64 + '.' + playload_B64;

function encript(data, key){
	let ciper = crypto.createCipher('aes-256-cbc', key);
	let crypted = ciper.update(data, 'utf-8', 'hex');
	crypted += ciper.final('hex');
	return crypted;
}

let encryped_data = encript(data, "654548125");

let JWT = data + '.' + encryped_data;
console.log(JWT);

