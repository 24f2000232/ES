/* PR 1: LED Blinking + JTAG/SWD Debugging (STM32F407G)
 * CubeMX: PD15 -> GPIO_Output (Blue LED LD6)
 *
 * SWD Debugging Steps (STM32CubeIDE):
 * 1. Build (Ctrl+B) -> Click Debug (F11) with SWD interface.
 * 2. Double-click left margin on both HAL_GPIO_WritePin lines to set Breakpoints.
 * 3. Press F8 (Resume) to stop at Breakpoint 1, then F6 (Step Over) -> LED ON.
 * 4. Inspect CPU Registers: Window -> Show View -> Registers (PC, SP, LR).
 * 5. Inspect GPIO Registers: Window -> Show View -> SFRs -> GPIOD -> ODR (Bit 15 = 1).
 */

while (1)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);    // Breakpoint 1: LED ON
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);  // Breakpoint 2: LED OFF
    HAL_Delay(100);
}
