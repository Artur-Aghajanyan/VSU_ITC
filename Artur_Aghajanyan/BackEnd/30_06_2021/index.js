const http = require('http');

http.createServer((req, res) => {
  if (req.url === '/' && req.method === 'GET') {
    res.write(`This is page for method ${req.method}`);
	console.log(req.method);
  } else if (req.url === '/test1' && req.method === 'POST') {
    res.write(`This is page for method ${req.method}`);
    console.log(req.method); 
  } else if (req.url === '/test2' && req.method === 'PUT') {
    res.write(`This is page for method ${req.method}`);
    console.log(req.method);
  } else if (req.url === '/test3' && req.method === 'DELETE') {
    res.write(`This is page for method ${req.method}`);
	console.log(req.method);
  } else {
	console.log(req.method);
	res.write('Page not found!!');
  }
  res.end();
}).listen(8080);
