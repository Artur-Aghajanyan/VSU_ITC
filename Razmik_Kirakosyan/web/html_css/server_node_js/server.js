const { ENETDOWN } = require('constants');
const http = require('http');
 
    const server = http.createServer(function (req, res){
    if (req.method === "GET") {
        console.log("get");
    } else if(req.method === "POST") {
        let body ="";
        req.on('data', chunk => {body+=chunk.toString()})
        req.on('end', () => {console.log(body)});
    } 

    res.writeHead(200);
    res.end("Hello world!");
});
server.listen(8080);