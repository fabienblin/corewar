/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   visu.js                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:31:01 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:25:41 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

var http = require('http');
var fs = require('fs');
var readline = require('readline');

// Chargement du fichier index.html affiché au client
var server = http.createServer(function(req, res) {
    fs.readFile(`${__dirname}/visu.html`, 'utf-8', function(error, content) {
        //res.writeHead(200, {"Content-Type": "text/html"});
        res.end(content);
    });
});

var io = require('socket.io').listen(server);

// io.sockets.on('connection', function (socket) {
// 	process.stdin.on('data', function (data){
// 		console.log(data.toString());
// 		socket.emit("turn", data.toString());
// 	});
// });

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false,
  crlfDelay:100
});

io.on('connection', function (socket) {
	rl.on('line', (line) => {
		console.log(line);
		socket.emit("turn", line);
		//socket.emit("turn", "holaaaaa");
	});
});

server.listen(8080);