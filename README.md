# Embedded Systems (ES) Practicals — T.Y. ECE

All 12 practical codes for **STM32F407G (STM32CubeIDE)** and **ESP32 (Arduino IDE)**, with wiring and quick setup notes.

## Practicals & Board Requirements

| PR | Practical | Board | Folder |
|----|-----------|-------|--------|
| 1 | LED blinking + JTAG/SWD debugging | STM32 compulsory | `PR01_02_03_STM32_LED_SquareWave_Debug/` |
| 2 | 50% duty-cycle square wave + oscilloscope | STM32 compulsory | `PR01_02_03_STM32_LED_SquareWave_Debug/` |
| 3 | Instruction-level debugging (PC, SP, LR, GPIO) | STM32 compulsory | `PR01_02_03_STM32_LED_SquareWave_Debug/` |
| 4 | SG90 Servo motor (50 Hz PWM: 0°, 90°, 180° for 2s) | STM32 compulsory | `PR04_STM32_Servo_SG90/` |
| 5 | BLDC motor + ESC (smooth 1 ms ↔ 2 ms ramp) | STM32 compulsory | `PR05_STM32_BLDC_ESC/` |
| 6 | DHT11 / DHT22 Temp & Humidity | ESP32 compulsory | `PR06_ESP32_DHT11/` |
| 7 | LDR Automatic Lighting | STM32 / ESP32 | `PR07_LDR_AutoLight/` |
| 8 | MQ-series Gas Sensor + Alert | STM32 / ESP32 | `PR08_MQ_GasSensor/` |
| 9 | BMP280 Pressure Sensor | STM32 / ESP32 | `PR09_ESP32_BMP280/` |
| 10 | Ultrasonic HC-SR04 Distance (cm) | STM32 / ESP32 | `PR10_ESP32_Ultrasonic/` |
| 11 | Soil Moisture + Temp over Wi-Fi (ESP32 ↔ ESP32) | ESP32 compulsory | `PR11_ESP32_WiFi_Transmitter_Receiver/` |
| 12 | DHT11 / LDR + MQTT + ThingSpeak | ESP32 compulsory | `PR12_ESP32_MQTT_ThingSpeak/` |

---

## Quick Notes

### PR 1–3: SWD Debugging in STM32CubeIDE
1. Build (`Ctrl+B`) → Click **Debug** (Bug icon / `F11`) with **SWD** interface.
2. Double-click left margin on `HAL_GPIO_WritePin(...)` lines to set **Breakpoints**.
3. Controls: `F8` Resume, `F6` Step Over, `F5` Step Into, `F7` Step Return.
4. **CPU Registers:** `Window → Show View → Registers` (`PC`, `SP`, `LR`, `xPSR`).
5. **GPIO Registers:** `Window → Show View → SFRs → GPIOD → ODR` (Bit 15 toggles `0x8000` / `0x0000` for `PD15`).

### PR 4–5: TIM3 PWM Settings (50 Hz)
- **Channel:** `TIM3_CH1` (`PA6`)
- **Prescaler (PSC):** `15` (at 16 MHz clock) or `83` (at 84 MHz clock) → **1 µs per tick**
- **Counter Period (ARR):** `19999` → `20,000 µs = 20 ms = 50 Hz`
