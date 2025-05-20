
# 📉 Real-Time Low-Pass FIR Filter for Accelerometer Data

This project implements a **real-time low-pass FIR filter** using a **Hamming window** to process motion data from a 3-axis accelerometer. Designed for embedded systems, the filter runs on an **STM32 microcontroller** using the **CMSIS-DSP library** for efficient, high-performance signal processing.

---

## 🎯 Objectives

- Filter high-frequency noise from accelerometer data using a FIR filter.
- Implement the filter in real-time on an STM32 MCU using CMSIS-DSP.
- Acquire data via I2C from the sensor and send filtered output over UART.

---

## ⚙️ System Overview

```text
Accelerometer (via I2C)
        ↓
  STM32 MCU (CMSIS-DSP FIR Filter)
        ↓
Filtered Data (via UART)
