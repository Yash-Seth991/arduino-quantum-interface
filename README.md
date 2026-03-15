# ⚛️ Arduino–Quantum Interface

A minimal proof-of-concept that bridges classical embedded hardware (Arduino) with a quantum computing simulator, visualizing a single **qubit measurement** in real time using an RGB LED.

> *One qubit. One measurement. One physical result.*

---

## 🧠 The Idea

Real quantum computers are expensive to access and impossible to own. IBM charges by compute minute. But the *interface pattern* — a classical controller receiving output from a quantum processor — is something that can be learned and replicated at home.

This project replicates that pattern in its purest form:
- A **single-qubit quantum circuit** is built and measured in Python using Qiskit
- The result (0 or 1) is sent over serial to an Arduino
- The Arduino drives an **RGB LED** — red for |0⟩, blue for |1⟩

The qubit is placed in superposition before measurement, so the outcome is genuinely probabilistic. Neither the program nor the hardware knows the result until the moment of collapse.

---

## ⚙️ How It Works

```
[Python — quantum_interface.py]
  → builds 1-qubit circuit
  → applies Hadamard gate → qubit enters superposition
  → measures qubit → collapses to '0' or '1'
  → sends result over serial (USB) to Arduino

[Arduino — quantum_interface.ino]
  → reads '0' or '1' from serial
  → '0' → RED LED on   (represents |0⟩)
  → '1' → BLUE LED on  (represents |1⟩)
```

---

## 🔬 What It Demonstrates

| Quantum Concept | Physical Representation |
|---|---|
| Hadamard gate | Qubit placed in 50/50 superposition |
| Wavefunction collapse | LED snaps to red or blue on measurement |
| Quantum randomness | Each run produces a non-deterministic result |

---

## 🔌 Hot-Swappable Quantum Backend

The simulator can be swapped for real IBM Quantum hardware with minimal changes:

```python
# Default — local Aer simulator, free and offline
sim = AerSimulator()
job = sim.run(circuit, shots=1, memory=True)

# Real quantum hardware (requires IBM Quantum account)
# from qiskit_ibm_runtime import QiskitRuntimeService, SamplerV2
# service = QiskitRuntimeService()
# backend = service.least_busy(operational=True, simulator=False)
```

> The circuit and serial logic are identical either way — true hardware abstraction.

---

## 🛠️ Tech Stack

| Layer | Technology |
|---|---|
| Quantum circuit | Qiskit (Python) — single-qubit Hadamard + measurement |
| Quantum backend | IBM Aer Simulator (hot-swappable to real IBM QPU) |
| Serial bridge | PySerial (Python) |
| Embedded controller | Arduino (C++) |
| Physical output | RGB LED (red = \|0⟩, blue = \|1⟩) |

---

## 📦 Setup & Installation

### Hardware Required
- Arduino Uno or Nano
- RGB LED (common cathode) + 2x 220Ω resistors
- Jumper wires

### Wiring

| Arduino Pin | RGB LED Pin |
|---|---|
| D9 | Red |
| D10 | Blue |
| GND | Common cathode |

### Python Dependencies
```bash
pip install qiskit qiskit-aer pyserial
```

### Upload & Run
1. Open `quantum_interface.ino` in Arduino IDE
2. Select your board and port, then upload
3. Update the COM port in `quantum_interface.py`:
```python
arduino = serial.Serial('COM3', 115200, timeout=0.1)
# arduino = serial.Serial('/dev/ttyUSB0', 115200)  # Linux/Mac
```
4. Run the Python script:
```bash
python quantum_interface.py
```
The LED will flash red or blue — a physical register of a quantum measurement.

---

## 📁 File Structure

```
arduino-quantum-interface/
├── quantum_interface.ino    # Arduino sketch — reads serial, drives LED
├── quantum_interface.py     # Python — quantum circuit + serial bridge
└── README.md
```

---

## 📰 Related Writing

- [The Closest I Got to Having a Quantum Computer at Home](https://medium.com/@yashseth991)
- [Why Quantum Computing is Still a Dream](https://medium.com/@yashseth991)

---

## 👤 Author

**Yash Seth**
[LinkedIn](https://linkedin.com/in/yash-seth-aab34b340) · [Medium](https://medium.com/@yashseth991) · [GitHub](https://github.com/Yash-Seth991)
