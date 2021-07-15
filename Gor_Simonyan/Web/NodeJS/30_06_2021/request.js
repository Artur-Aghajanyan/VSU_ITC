const http = require('http')

const data = JSON.stringify({
    'msg': 'Hello, I am request!'
})

const options = {
    hostname: '127.0.0.1',
    port: 8080,
    path: '/',
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'Content-Length': data.length
    }
}

const req = http.request(options, response => {
    console.log(`statusCode: ${response.statusCode}`)

    response.on('data', chunk => console.log(`BODY: ${chunk}`))

    response.on('end', () => console.log('No more data in response.'))
})

req.on('error', error => console.log((error)))

req.write(data)
req.end()