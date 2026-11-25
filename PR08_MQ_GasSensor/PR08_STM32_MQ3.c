/* PR 8: MQ-Series Gas Sensor (STM32F407G)
 * CubeMX: ADC1_IN1 (PA1), PD12 -> GPIO_Output, USART3 -> 115200 baud
 * Includes: #include <stdio.h>
 * Variables: uint32_t adc_value = 0; char msg[30];
 */

while (1)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    adc_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, (adc_value > 2000) ? GPIO_PIN_SET : GPIO_PIN_RESET);

    int len = sprintf(msg, "Gas: %lu\r\n", adc_value);
    HAL_UART_Transmit(&huart3, (uint8_t *)msg, len, 100);
    HAL_Delay(500);
}
