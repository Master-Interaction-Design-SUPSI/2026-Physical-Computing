import { SerialDevice } from './webSerial.js'

// serial terminal
const connectBtn = document.getElementById("serial-connection");
const textOutput = document.getElementById("text-output");
const messageInput = document.getElementById("message-input");
const sendBtn = document.getElementById("send-message");

// neopixels
const colorInput = document.getElementById("color-input");
const minIndex = document.getElementById("min-index");
const maxIndex = document.getElementById("max-index");
const sendColorBtn = document.getElementById("send-color");

// Joystick values
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
    textOutput.textContent += msg;
    textOutput.scrollTop = textOutput.scrollHeight;
    msg = msg.trim();

    const values = msg.split(',');  // split string by comma
    
    xBar.style.width = values[0] + "%";
    yBar.style.width = values[1] + "%";
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


sendColorBtn.addEventListener("click", () => {
    const iStart = minIndex.value;
    const iStop = maxIndex.value;
    const hexColor = colorInput.value;

    const r = parseInt(hexColor.slice(1, 3), 16);
    const g = parseInt(hexColor.slice(3, 5), 16);
    const b = parseInt(hexColor.slice(5, 7), 16);

    const msg = "P," + r + "," + g + "," + b + "," + iStart + "," + iStop;

    arduino.sendMessage(msg);
    console.log(msg);

});