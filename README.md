## STM32F042 Board

Dev board for the
[STM32F042](https://www.st.com/resource/en/datasheet/stm32f042c4.pdf).

Basic linker script, headers, hello world program, and notes are given in [programming](./programming).

Dimensions: 1.63in (41.50mm) x 0.74 in (18.80mm); headers 0.6in (15.24mm) center to center.

USB C receptacle for USB 2.0.

There is also a [Micro-USB version](https://github.com/jedp/STM32F042-dev-board/releases/tag/Micro-USB).

![Finished Board](jedboard-usbc.jpg)

![PCB Front Rendering](front.png)

![PCB Back Rendering](back.png)

## BOM

### USB Section

- J3: USB C USB 2.0 Receptacle, GCT USB4105-xx-A
- U3: USBLC6-2SC6 Power protection, SOT-23-6
- FB1: BK0603HS330-T Ferrite bead, 0805
- R1: 0k DNP, 0603
- R6: 5.1k, 0603
- R7: 5.1k, 0603
- C9: 0.01u, 0805
- C10: 0.1u, 0805
- C11: 4.7u, 1206

Test:

- USB VBUS voltage
- 5V VBUS
- GND
- USB D- at MCU pin 17
- USB D+ at MCU pin 18

### 3V3 Regulator

- U2: MCP1802 3v3 Linear regulator, SOT-23-5
- C1: 1u, 0805
- C3: 10u, 0805
- C5: 1u, 0805
- R5: 1k, 0603
- D2: LED PWR, 0603

Test:

- 3V3 BUS
- 3V3 at MCU pins 5, 16
- GND at MCU pin 15

### Microcontroller

- U1: STM32F042F6Px, TSSOP-20
- C2: 0.1u, 0603
- C4: 0.1u, 0603
- D1: LED USER, 0603
- JP1: Solder Jumper Boot: Solder pad 0 for normal use.
- R3: 10k, 0603
- R4: 1k, 0603
- Reset1: SW Push, SPST B3U-1000P-B

### Headers, JTAG/SWD

- J1: Conn 01x12 Female, PinSocket 2.54mm
- J2: Conn 01x12 Female, PinSocket 2.54mm
- J5: JTAG/SWD, PinHeader 2x05, 1.27mm

Test:

- Flash blinky program
- Resest using Reset1

