let url = require('url');

let fs = require('fs');
let path = require('path');
var readline = require('readline');

var express = require('express');
var app = express();
let http = require('http').Server(app);
var io = require('socket.io')(http);

var _ = require('lodash');

app.use(express.static(path.join(__dirname, 'public')));

app.get('/', function(req, res) {
  res.sendFile( __dirname + "/views/visu.html" );
});

const { spawn } = require('child_process');
const ls = spawn('../a.out');

io.sockets.on('connection', function (socket) {
	ls.stdout.on('data', (data) => {
		socket.emit("turn", data.toString());
	});
});

//var server = http.createServer(app);



// io.sockets.on('connection', function (socket) {
// 	process.stdin.on('data', function (data){
// 		console.log(data.toString());
// 		socket.emit("turn", data.toString());
// 	});
// });
/*
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false,
  crlfDelay:100
});

io.on('connection', function (socket) {
	rl.on('line', (line) => {
		socket.emit("turn", line);
	});
});
*/

http.listen(8080);