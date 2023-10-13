const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);
const { v4: uuidv4 } = require('uuid');
const { ExpressPeerServer } = require('peer');
const peerServer = ExpressPeerServer(server, {
  debug: true
})

app.set('view engine', 'ejs');
app.use(express.static('public'))

app.use('/peerjs', peerServer);
app.get('/', (req, res) => {
  res.redirect(`/${uuidv4()}`);
});

app.get('/:chatroom', (req, res) => {
  res.render('chatroom', { roomId: req.params.room });
});
io.on('connection', socket => {
  socket.on('join-server', (roomId) => {
    socket.join(roomId);
    io.to(roomId).emit('user-connected');
    // tell that someone joined.
  });
});



server.listen(3500);
