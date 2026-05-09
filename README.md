# Digispark HID Mouse Mover

A simple Digispark sketch that moves the mouse cursor randomly to **prevent the computer from sleeping or activating the screensaver** — no clicks, just cursor movement.

Plug it in and it works instantly. The host PC sees it as a generic **HID mouse** — no drivers needed, no "Digispark" name visible in Device Manager.

---

## Hardware Required

- [Digispark (ATtiny85) USB board](http://digistump.com/products/1)

---

## Setup & Installation

### 1. Add Digistump Board URL
In Arduino IDE go to **File → Preferences** and add this to *Additional Board Manager URLs*:
```
https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json
```

### 2. Install Digistump AVR Boards
- Go to **Tools → Board → Boards Manager**
- Search `digistump`
- Install **Digistump AVR Boards**

### 3. Install DigiMouse Library
- Go to **Sketch → Include Library → Manage Libraries**
- Search `DigiMouse`
- Click **Install**

### 4. Install Drivers (Windows)
Download and run `DPinst64.exe` from the [Digistump releases page](https://github.com/digistump/DigistumpArduino/releases).

### 5. Select Board
- **Tools → Board → Digistump AVR Boards → Digispark (Default - 16.5mhz)**

---

## Uploading

> ⚠️ Digispark uploads differently from normal Arduino boards!

1. Open `digispark_mouse_mover.ino` in Arduino IDE
2. Click **Upload**
3. Wait until the console says:
   ```
   > Please plug in the device...
   ```
4. **Only then** plug in your Digispark
5. Upload completes automatically ✅

---

## Configuration

You can tweak these values at the top of the sketch:

| Setting | Default | Description |
|---|---|---|
| `MOVE_INTERVAL` | `2000` | Milliseconds between movements |
| `MOVE_RANGE` | `20` | Max pixels to move in any direction |

---

## How It Works

- Every `MOVE_INTERVAL` ms the cursor moves a small pseudo-random amount
- Uses `millis()` for varied X/Y offsets — no extra libraries needed
- No mouse clicks are ever sent
- Enumerates as a standard **HID-compliant mouse** — invisible to the host OS

---

## Tested On

- Windows 10 / 11
- Arduino IDE 2.3.x
- Digispark ATtiny85 clone boards

---

## License

MIT — free to use, modify, and share.
