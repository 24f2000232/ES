/* PR 2: 50% Duty-Cycle Square Wave + Oscilloscope (STM32F407G)
 * CubeMX: PD15 -> GPIO_Output
 *
 * Equal ON time (100 ms) and OFF time (100 ms):
 * - Total Period (T) = 200 ms -> Frequency = 5 Hz, Duty Cycle = 50%
 *
 * Verification:
 * 1. SWD Debug: Check GPIOD->ODR Bit 15 toggling 0x8000 (HIGH) <-> 0x0000 (LOW).
 * 2. Oscilloscope: Connect Probe (+) to PD15 and GND (-) to board GND.
 */

while (1)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);    // HIGH for 100 ms
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);  // LOW for 100 ms
    HAL_Delay(100);
}
