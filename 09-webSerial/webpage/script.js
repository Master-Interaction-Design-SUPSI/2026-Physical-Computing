import { SerialDevice } from './webSerial.js'

const connectBtn = document.getElementById("serial-connection");

const arduino = new SerialDevice({
    baudRate: 9600,
    connectButton: connectBtn,
    onMessage: msg => handleMessages(msg),
    onConnect: () => arduinoConnected(),
    onDisconnect: () => arduinoDisconnected()
});


function handleMessages(msg) {
    console.log("Arduino says: " + msg);
}

function arduinoConnected() {
    console.log("Connected to Arduino");
}

function arduinoDisconnected() {
    console.log("Disconnected from Arduino");
}