var http = require('http');
var server = new http.Server();
server.listen(8080, function() {
    console.log("listening on port: ", +8080);
});
