const express = require('express');
const http = require('http');
const WebSocket = require('ws');

const app = express();
const server = http.createServer(app);
const wss = new WebSocket.Server({ server });

// Xử lý kết nối vào WebSocket server
wss.on('connection', (ws) => {
  // Xử lý các sự kiện và thông tin từ client

  // Gửi tin nhắn tới client
  ws.send('Hello from WebSocket server!');
});

// Xử lý các yêu cầu HTTP thông qua đường dẫn '/'
app.get('/', (req, res) => {
  res.send('Hello from HTTP server!');
});

// Khởi động server
server.listen(3000, () => {
  console.log('Server is running on port 3000.');
});