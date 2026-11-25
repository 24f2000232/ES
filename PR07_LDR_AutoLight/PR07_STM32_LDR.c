/* PR 7: LDR Automatic Lighting (STM32F407G)
 * CubeMX: PC5 -> GPIO_Input (LDR DO), PD12 -> GPIO_Output (Green LED LD4)
 */

while (1)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_RESET)
    {
        // Dark: LED ON
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
    }
    else
    {
        // Bright: LED OFF
        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
    }
    HAL_Delay(200);
}
