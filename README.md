# Arduino Temperature Sensor LED Alert System (TMP36/LM35)
 
## 📌 Project Overview
 
This project demonstrates a **temperature monitoring and LED alert system** using an **Arduino Uno** and an **analog temperature sensor (TMP36/LM35)**. The system continuously reads the surrounding temperature, converts the analog signal into a Celsius value, and **automatically turns an LED ON when the temperature exceeds a defined threshold (30°C)**. The real-time temperature data is also displayed on the **Serial Monitor** for easy observation and debugging.

This project is ideal for beginners learning:

* Analog sensor interfacing
* Arduino programming  
* Conditional logic  
* Real-time hardware monitoring 
 
---
 
## 🚀 Features  

* 📊 Real-time temperature monitoring via Serial Monitor
* 🌡️ Analog to digital temperature conversion
* 💡 Automatic LED alert when temperature exceeds threshold
* 🔁 Continuous data refresh every 1 second 
* 🛠️ Easy to modify threshold and output devices 

---

## 🧰 Components Used

| Component                          | Quantity    |
| ---------------------------------- | ----------- |
| Arduino Uno R3                     | 1           |
| Temperature Sensor (TMP36 or LM35) | 1           |
| LED                                | 1           |
| 220Ω Resistor                      | 1           |
| Jumper Wires                       | As required |
| Breadboard (Optional)              | 1           |

---

## 🔌 Circuit Connections

### Temperature Sensor (TMP36 / LM35)

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| OUT        | A0          |

### LED

| LED Pin     | Arduino Pin                       |
| ----------- | --------------------------------- |
| Anode (+)   | Digital Pin 8 (via 220Ω resistor) |
| Cathode (-) | GND                               |

---

## 🖥️ Arduino Code

```cpp
// Pin definitions
int tempPin = A0;   // Temperature sensor output
int ledPin = 8;    // LED connected to digital pin 8

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempPin);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature (LM35: 10mV per °C)
  float tempC = (voltage - 0.5) * 100;  

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  // LED control logic
  if (tempC >= 30.0) {
    digitalWrite(ledPin, HIGH); // LED ON
  } else {
    digitalWrite(ledPin, LOW);  // LED OFF
  }

  delay(1000);
}
```

---

## 📸 Simulation Preview

This project was designed and tested using **Tinkercad Circuits**. The simulation demonstrates:

* LED turning ON when temperature crosses 30°C
* Real-time temperature updates on Serial Monitor
* Accurate analog sensor readings

You can add screenshots in a folder named:

```
/assets
```

And link them in this README like:

```md
![Circuit Diagram](assets/circuit.png)
```

---

## ⚙️ How It Works

1. The temperature sensor outputs an **analog voltage** proportional to temperature
2. Arduino reads this value using `analogRead()`
3. Voltage is converted into **Celsius** using a mathematical formula
4. If the temperature exceeds **30°C**, the LED turns ON
5. Temperature data is printed to the **Serial Monitor**

---

## 🧪 Applications

* Smart home temperature alerts
* Overheating detection systems
* Basic weather monitoring
* IoT-based sensor projects
* Embedded systems learning

---

## 🏗️ Future Enhancements

* Add LCD display for standalone temperature display
* Integrate buzzer for audible alerts
* Upload temperature data to cloud (IoT integration)
* Add mobile app dashboard
* Multi-sensor temperature monitoring

---

## 📁 Project Structure

```
Arduino-Temperature-Alert-System
│
├── code
│   └── temperature_alert.ino
├── assets
│   └── circuit.png
├── README.md
```

---

## 🧑‍💻 Author

**Avinash Verma**
B.Tech CSE (AI) Student | Embedded Systems & IoT Enthusiast

---

## ⭐ Support

If you found this project helpful:

* Star this repository ⭐
* Fork it 🔱
* Share it with fellow learners 👨‍💻👩‍💻

---

## 📜 License

This project is licensed under the **MIT License** – feel free to use, modify, and distribute it for educational and personal projects.

---

## 🔖 Tags

`#Arduino` `#IoT` `#EmbeddedSystems` `#TemperatureSensor` `#OpenSource` `#GitHubProjects` 
