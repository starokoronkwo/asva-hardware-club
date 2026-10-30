# Robotic Arm Circuit (Proteus Simulation)

A six-servo robotic arm circuit designed and simulated in Proteus, controlled by an Arduino Uno. Each servo (M1–M6) is driven from its own digital pin, and all six are powered from an external battery rather than from the Arduino.



---

## Circuit and simulation

### Circuit schematic

![Circuit schematic in Proteus]

### Simulation video

[Watch the simulation demo]

> If the video does not play on GitHub, click the link above and use the download button.


---

## Components

| Component | Quantity | Notes |
|---|---|---|
| Arduino Uno | 1 | ATmega328P, 16 MHz |
| Servo motor (MG995) | 6 | M1–M6, the joints of the arm |
| Battery (BAT1) | 1 | 5 V external supply for the servos |

---

## Pin connections

| Servo | Arduino pin |
|---|---|
| M1 | 2 |
| M2 | 3 |
| M3 | 4 |
| M4 | 5 |
| M5 | 6 |
| M6 | 7 |

### Power and ground

- **Servo power (red wires):** all six servos connect to the battery positive through a shared net named `VS`.
- **Ground (brown wires):** all six servos, the battery negative and the Arduino GND share one common ground.
- **Signal (orange wires):** each servo's signal wire goes to its own Arduino pin (see the table above).
- The servos are powered by the battery, **not** by the Arduino 5V pin, because six servos draw more current than the Arduino can supply.

---

## How it works

On start-up the Arduino attaches each servo and centres it at 90°, staggering the start to limit inrush current. It then loops forever, sweeping each servo in turn:

`90° → 45° → 135° → 90°`

Movements are made one degree at a time with a short delay, so the arm moves smoothly instead of jerking.

---

