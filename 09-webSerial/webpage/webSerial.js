/*
webSerial.js - A clean, reusable ES module for Web Serial connections (Arduino example)
Copyright (c) 2026 Marco Lurati

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

export class SerialDevice {
    constructor({ 
        baudRate = 9600, 
        onMessage = () => {}, 
        onConnect = () => {}, 
        onDisconnect = () => {}, 
        connectButton = null 
    } = {}) {
        this.port = null;
        this.reader = null;
        this.writer = null;
        this.baudRate = baudRate;
        this.onMessage = onMessage;
        this.onConnect = onConnect;
        this.onDisconnect = onDisconnect;

        // Optional connect button
        if (connectButton) {
            connectButton.addEventListener("click", () => this.connect());
            this.connectButton = connectButton;
            this.updateButton();
        }
    }

    async connect() {
        if (this.port) return this.disconnect();

        let ports = await navigator.serial.getPorts();
        if (ports.length === 0) {
            await navigator.serial.requestPort();
            ports = await navigator.serial.getPorts();
        }

        if (ports.length > 0) {
            await this.openPort(ports[0]);
        } else {
            alert("No serial ports available.");
        }
    }

    async openPort(selectedPort) {
        try {
            this.port = selectedPort;
            await this.port.open({ baudRate: this.baudRate });

            this.writer = this.port.writable.getWriter();
            this.reader = this.port.readable.getReader();

            console.log("Serial connected");
            this.onConnect();
            this.updateButton();
            this.readLoop();
        } catch (error) {
            this.port = null;
            alert("Serial port already in use! Close other connections (e.g., Arduino IDE Serial Monitor).");
            console.error(error);
        }
    }

    async disconnect() {
        try {
            if (this.reader) {
                await this.reader.cancel().catch(() => {});
                this.reader.releaseLock();
                this.reader = null;
            }

            if (this.writer) {
                this.writer.releaseLock();
                this.writer = null;
            }

            if (this.port) {
                await this.port.close();
                this.port = null;
            }

            console.log("Serial disconnected");
            this.onDisconnect();
            this.updateButton();
        } catch (error) {
            console.error("Error during disconnect:", error);
        }
    }

    async sendMessage(msg) {
        if (!msg || !this.writer) return;
        try {
            await this.writer.write(new TextEncoder().encode(msg));
        } catch (error) {
            console.error("Write error:", error);
        }
    }

    async readLoop() {
        while (this.reader) {
            try {
                const { value, done } = await this.reader.read();
                if (done) break;

                const msg = new TextDecoder().decode(value);
                this.onMessage(msg);
            } catch (error) {
                console.error("Read error:", error);
                await this.disconnect();
                break;
            }
        }
    }

    updateButton() {
        if (!this.connectButton) return;
        this.connectButton.textContent = this.port ? "Disconnect" : "Connect";
    }
}