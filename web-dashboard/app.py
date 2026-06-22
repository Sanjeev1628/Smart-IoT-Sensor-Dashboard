from flask import Flask, render_template
import serial

app = Flask(__name__)

@app.route('/')
def home():
    sensor_data = {
        "temperature": "28°C",
        "humidity": "65%"
    }
    return render_template("index.html", data=sensor_data)

if __name__ == "__main__":
    app.run(debug=True)
