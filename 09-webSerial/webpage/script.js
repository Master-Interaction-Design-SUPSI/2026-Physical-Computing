import { SerialDevice } from './webSerial.js'

const connectBtn = document.getElementById("serial-connection");
const textOutput = document.getElementById("text-output");
const messageInput = document.getElementById("message-input");
const sendBtn = document.getElementById("send-message");

const arduino = new SerialDevice({
    baudRate: 9600,
    connectButton: connectBtn,
    onMessage: msg => handleMessages(msg),
    onConnect: () => arduinoConnected(),
    onDisconnect: () => arduinoDisconnected()
});

function handleMessages(msg) {
    console.log("Arduino says: " + msg);
    textOutput.textContent += msg;
}

function arduinoConnected() {   
    console.log("Connected to Arduino");
}

function arduinoDisconnected() {
    console.log("Disconnected from Arduino");
    textOutput.textContent = "";    // clear text area
}

sendBtn.addEventListener("click", () => {
    const msg = messageInput.value;     // read input text
    

    if(msg.length > 0) {
        console.log("Sendig: " + msg);
        arduino.sendMessage(msg);      // sending message via library
    }

});