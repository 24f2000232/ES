/* PR 3: Instruction-Level Debugging (STM32F407G)
 * CubeMX: PD15 -> GPIO_Output
 *
 * Breakpoints & Register Observation:
 * - Hardware Breakpoint: Uses CPU FPB unit, works in Flash (limited, e.g. 6 on Cortex-M4).
 * - Software Breakpoint: Replaces instruction with BKPT, used in RAM (unlimited).
 * - Set breakpoints at HAL_GPIO_WritePin lines; use F5 (Step Into) to enter HAL function.
 *
 * Registers to Observe (Window -> Show View -> Registers / SFRs):
 * - PC (R15): Current instruction address (increments on every F6 Step Over).
 * - LR (R14): Return address saved when F5 Step Into enters HAL_GPIO_WritePin / HAL_Delay.
 * - SP (R13): Stack top address (changes during function calls).
 * - GPIOD->BSRR & GPIOD->ODR: Bit 15 updates atomically on SET/RESET.
 */

while (1)
{
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);    // Step Into (F5) to see LR, SP, BSRR
    HAL_Delay(100);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);  // Observe PC, ODR bit 15 = 0
    HAL_Delay(100);
}
