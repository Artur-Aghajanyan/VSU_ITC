const http = require('http')
const url = require('url')
const { parse } = require('querystring')

http.createServer(function (request, response){
    if (request.method === "GET") {
        response.writeHead(200, {'Content-Type': 'text/html'})
        let requestUrl = url.parse(request.url, true)
        if (requestUrl.query.test % 2 === 0) {
            console.log("Even")
            response.end("Even")
        }
        console.log("Odd")
        response.end("Odd")
    }
    else if (request.method === "POST"){
        let body = ""

        request.on('data', chunk => body += chunk.toString())

        request.on('end', () => console.log(body))

        response.end("ok")
    }
    else if (request.method === "PUT"){
        console.log("PUT")
        response.end("ok")
    }
    else if (request.method === "DELETE"){
        console.log("DELETE")
        response.end("ok")
    }
}).listen(8080)




