const crypto = require('crypto')

const header = {
    "id": "1",
    "name": "User"
}

const payload = {
    "surname": "surname",
    "work": "developer",
    "phone": "095625541"
}

const secret = "secret-key-111"

const buff = new Buffer(JSON.stringify(header)).toString("base64")
const buff2 = new Buffer(JSON.stringify(payload)).toString("base64")

const hash = crypto.createHmac("sha256",secret).update(buff + "." + buff2 + ".").digest("hex")

const buff3 = new Buffer(JSON.stringify(hash)).toString("base64")

console.log(buff + "." + buff2 + "." + buff3)