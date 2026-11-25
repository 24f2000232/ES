/* PR 1, 2, 3: LED Blinking & 50% Duty-Cycle Square Wave (STM32F407G)
 * Pin: PD15 (Blue LED LD6) -> GPIO_Output
 * Period: 100 ms ON + 100 ms OFF = 200 ms (5 Hz, 50% duty cycle)
 *
 * Debugging (SWD):
 * - Set breakpoints on the two HAL_GPIO_WritePin lines.
 * - Inspect CPU registers: PC, SP, LR (Window -> Show View -> Registers).
 * - Inspect GPIO registers: GPIOD->ODR bit 15 (Window -> Show View -> SFRs).
 */

while (1)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);    // Breakpoint 1: LED ON (ODR bit 15 = 1)
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);  // Breakpoint 2: LED OFF (ODR bit 15 = 0)
    HAL_Delay(100);
}
