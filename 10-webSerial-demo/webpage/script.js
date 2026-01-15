import { SerialDevice } from './webSerial.js'

const connectBtn = document.getElementById("serial-connection");
const textOutput = document.getElementById("text-output");
const messageInput = document.getElementById("message-input");
const sendBtn = document.getElementById("send-message");

const xBar = document.getElementById("x-value");
const yBar = document.getElementById("y-value");

const arduino = new SerialDevice({
    baudRate: 9600,
    connectButton: connectBtn,
    onMessage: msg => handleMessages(msg),
    onConnect: () => arduinoConnected(),
    onDisconnect: () => arduinoDisconnected()
});

function handleMessages(msg) {

    msg = msg.trim();

    console.log("Arduino says: " + msg + "px");
    textOutput.textContent += msg;
    
    xBar.style.width = msg / 4 + "px";
}

function arduinoConnected() {   
    console.log("Connected to Arduino");
    messageInput.disabled = false;
    sendBtn.disabled = false;
}

function arduinoDisconnected() {
    console.log("Disconnected from Arduino");
    textOutput.textContent = "";    // clear text area
    messageInput.disabled = true;
    sendBtn.disabled = true;
}

sendBtn.addEventListener("click", () => {
    const msg = messageInput.value;     // read input text
    messageInput.value = "";    // clear input text
    
    if(msg.length > 0) {
        console.log("Sendig: " + msg);
        arduino.sendMessage(msg);      // sending message via library
    }

});