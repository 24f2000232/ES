/* PR 5: BLDC Motor + ESC (STM32F407G)
 * CubeMX: TIM3 -> CH1 (PA6) -> PWM Generation CH1
 * PSC = 15 (16 MHz) or 83 (84 MHz) -> 1 us tick
 * ARR = 19999 -> 20 ms (50 Hz)
 * Wiring: ESC Signal -> PA6, ESC GND -> GND, ESC Power -> 12V/LiPo
 */

HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

// Arm ESC at minimum throttle (1 ms)
__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 1000);
HAL_Delay(3000);

while (1)
{
    // Smooth acceleration: 1 ms -> 2 ms
    for (uint16_t pulse = 1000; pulse <= 2000; pulse += 10)
    {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse);
        HAL_Delay(50);
    }

    // Smooth deceleration: 2 ms -> 1 ms
    for (uint16_t pulse = 2000; pulse >= 1000; pulse -= 10)
    {
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse);
        HAL_Delay(50);
    }
}
