/* PR 4: SG90 Servo Motor (STM32F407G)
 * CubeMX: TIM3 -> CH1 (PA6) -> PWM Generation CH1
 * PSC = 15 (16 MHz) or 83 (84 MHz) -> 1 us tick
 * ARR = 19999 -> 20 ms (50 Hz)
 * Wiring: Signal -> PA6, VCC -> 5V, GND -> GND
 */

HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

while (1)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 500);   // 0 deg (0.5 ms)
    HAL_Delay(2000);

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1500);  // 90 deg (1.5 ms)
    HAL_Delay(2000);

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 2500);  // 180 deg (2.5 ms)
    HAL_Delay(2000);
}
