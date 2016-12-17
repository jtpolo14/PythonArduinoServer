
#get required packages
from flask import Flask, request, render_template
import serial, sys

#create flask app with the name of the program
app = Flask(__name__)

#Check if a serial port for the arduino was provided from the command line
# if so connect to the arduino, else output error and shutdown
if len(sys.argv) >= 2:
    #serial_port = '/dev/tty.usbmodem1421'
    #get the port given from the cmd line 
    serial_port = sys.argv[1]
    ser = serial.Serial(serial_port, 9600)
else:
    print('************************ ERROR ************************')
    print('Serial port of the arduino is required ')
    print('************************ ERROR ************************')
    sys.exit(0)


#create the api endpoints
@app.route("/")
def home():
    return render_template('index.html')

@app.route("/lights-red")
def getLightRed():
    ser.write(b'red')
    return render_template('index.html')

@app.route("/lights-yellow")
def getLightYellow():
    ser.write(b'yellow')
    return render_template('index.html')

@app.route("/lights-green")
def getLightGreen():
    ser.write(b'green')
    return render_template('index.html')

@app.route('/shutdown')
def shutdown():
    shutdown_server()
    return 'Server shutting down...'

#gracefully shutdown the server
def shutdown_server():
    func = request.environ.get('werkzeug.server.shutdown')
    if func is None:
        raise RuntimeError('Not running with the Werkzeug Server')
    func()

#main program body
if __name__ == "__main__":
    try:
        # start app. Use host '127.0.0.1' for development and
        #'0.0.0.0' to make the server available on the network
        app.run(host = '0.0.0.0')
    finally:
        # ensure server is shutdown correctly 
        shutdown_server()
