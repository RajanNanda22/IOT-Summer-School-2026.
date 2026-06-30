# Keypad + LCD Password-Protected Access System

## Objective

Create a password-protected access system using a 4x4 membrane keypad and a 16x2 LCD. The LCD prompts the user to enter a 4-digit PIN. A correct PIN grants access with a green LED, while an incorrect PIN activates a red LED and buzzer. After three incorrect attempts, the system locks for 10 seconds.

---

## Components Required

- Arduino Uno
- 4x4 Membrane Keypad
- 16x2 LCD
- Green LED
- Red LED
- Active Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Connections

### LCD

| LCD Pin | Arduino Pin |
|----------|-------------|
| RS | D12 |
| EN | D11 |
| D4 | D5 |
| D5 | D4 |
| D6 | D3 |
| D7 | D2 |

### Keypad

| Keypad Pin | Arduino Pin |
|-------------|-------------|
| R1 | A0 |
| R2 | A1 |
| R3 | A2 |
| R4 | A3 |
| C1 | A4 |
| C2 | A5 |
| C3 | D6 |
| C4 | D7 |

### Other Components

| Component | Arduino Pin |
|-----------|-------------|
| Green LED | D8 |
| Red LED | D9 |
| Buzzer | D10 |

---

## Default Password

```
1234
```

This password can be changed in the code:

```cpp
String password = "1234";
```

---

## Working

1. LCD displays **ENTER PIN:**.
2. User enters a 4-digit password using the keypad.
3. Correct password:
   - Displays **ACCESS GRANTED**
   - Turns ON the green LED
4. Incorrect password:
   - Displays **ACCESS DENIED**
   - Turns ON the red LED
   - Activates the buzzer
5. After three consecutive incorrect attempts:
   - Displays **SYSTEM LOCKED**
   - Locks the system for 10 seconds
6. After the lock period, the user can try again.

---

## Sample LCD Output

### Startup

```
ENTER PIN:
****
```

### Correct PIN

```
ACCESS
GRANTED
```

### Wrong PIN

```
ACCESS
DENIED
```

### Three Wrong Attempts

```
SYSTEM LOCKED
WAIT 10 SEC
```

---

## Expected Result

- LCD prompts the user to enter a PIN.
- Correct PIN grants access with the green LED.
- Incorrect PIN activates the red LED and buzzer.
- The system locks for 10 seconds after three consecutive incorrect attempts.
