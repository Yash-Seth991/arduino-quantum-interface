from qiskit import QuantumCircuit
from qiskit_aer import AerSimulator
import serial
import time

arduino = serial.Serial('COM3', 115200, timeout=0.1)
time.sleep(2)

circuit = QuantumCircuit(1, 1)
circuit.h(0)
circuit.measure(0, 0)

sim = AerSimulator()
job = sim.run(circuit, shots=1, memory=True)
result = job.result()

bit = result.get_memory()[0]
print("Qubit measurement:", bit)

arduino.write(bit.encode('utf-8'))
arduino.close()
