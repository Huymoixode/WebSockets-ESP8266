const socket = new WebSocket('ws://192.168.1.7:3000');

socket.addEventListener('open', (event) => {
    console.log('Connected to WebSocket server');
    socket.send('day la tu browser');
});

socket.addEventListener('message', (event) => {
    console.log('Received message from server:', event.data);
    // Xử lý tin nhắn từ server
    // khi nhận được tin từ Server sẽ thay đổi trạng thái của checkbox
    const message=event.data;
    if(message=='da tick'){
      checkbox.checked=true;

    }else if(message=='chua tick'){
      checkbox.checked=false;
    }
    // Hiển thị tin nhắn trên trang HTML
    // const messagesDiv = document.getElementById('messages');
    // messagesDiv.innerHTML += '<p>' + event.data + '</p>';
});

socket.addEventListener('close', (event) => {
    console.log('Connection closed');
});

socket.addEventListener('error', (event) => {
    console.error('WebSocket error:', event);
});
// socket.onopen=function(){
//     document.getElementById('status').innerHTML='connected';
    
// }
const button=document.getElementById('submit-btn');
button.onclick =(event)=>{
  socket.send('da tick');
  console.log('da tick');
};
//ket noi api
console.log("hello")
var cityname='hanoi';
const apikey='43b0485950ebbae8188565949bbaa0a2';

const keyapi="43b0485950ebbae8188565949bbaa0a2";
document.addEventListener('DOMContentLoaded', function() {
    document.getElementById('submit-btn').addEventListener('click', function() {
       cityname = document.getElementById('user-input').value;
        console.log(cityname)
        var url="https://api.openweathermap.org/data/2.5/weather?q="+cityname+"&appid="+apikey+"&units=metric";
        console.log(url)
        fetch(url)
.then(response => response.json())
.then(data => {
    var title=data.main.temp;
    var id=data.main.humidity;
    document.getElementById("temperature").innerHTML=title+" oC";
    document.getElementById("humidity").innerHTML=id+" %";
})
    });
  });


document.getElementById("temperature1").innerHTML="HELLO"