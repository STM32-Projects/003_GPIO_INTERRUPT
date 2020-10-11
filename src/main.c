/**
  ******************************************************************************
  * @file    main.c
  * @author  Supreeth
  * @version V1.0
  * @date    08-October-2020
  *
  * @brief   Illustrate the use of EXTI Block for External Interrupts
  *
  * Overview
  * ---------
  * This application toggle the User LED(LD2, Green), if there is a key press
  * event from the user otherwise the LED remains in OFF state.
  *
  * User LED(LD2, Green) is connected to PA5.
  * User Button(B1, Blue in Color) is connected to PC13
  *
  * Runs on stm32f446re
  *
  ******************************************************************************
*/


#include <stdbool.h>
#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"

void LED_Init();
void Button_Init();

/* Variable which control the behavior of LED blink */
volatile bool should_blink = false;

int main(void)
{
	HAL_Init();
	LED_Init();
	Button_Init();

	for(;;) {

		if (should_blink) {
			HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
			HAL_Delay(100);
		} else {
			HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
		}

		/*
		if (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_PORT,
				             USER_BUTTON_PIN) == GPIO_PIN_RESET) {
			HAL_GPIO_TogglePin(LED2_GPIO_PORT, LED2_PIN);
			HAL_Delay(100);
		} else {
			HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
		}
		*/
	}
}

/**********************************************************************
 *
 * @brief PortA Initialization for User LED(LD2, Green)
 *
 * User LED(LD2, Green) is connected to PA5.
 *
 * @param  None
 *
 * @return None
 *
 *********************************************************************/
void LED_Init()
{
	GPIO_InitTypeDef ledGPIO;

	/* Enable Clock for GPIOA Port */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	ledGPIO.Mode  = GPIO_MODE_OUTPUT_PP;
	ledGPIO.Pin   = LED2_PIN;
	ledGPIO.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(LED2_GPIO_PORT, &ledGPIO);
}


/**********************************************************************
 *
 * @brief PortC Initialization for User Button(B1, Blue)
 *
 * User Button(B1, Blue in Color) is connected to PC13.
 *
 * @param  None
 *
 * @return None
 *
 * @note Button has a built-in Pull Up Resistor. On pressing the button,
 * 		 the pin goes from a HIGH to LOW state.
 *
 *********************************************************************/
void Button_Init()
{
	GPIO_InitTypeDef btnGPIO;

	/* Enable Clock for GPIOC Port */
	__HAL_RCC_GPIOC_CLK_ENABLE();

	btnGPIO.Mode  = GPIO_MODE_IT_FALLING;
	btnGPIO.Pin   = USER_BUTTON_PIN;
	btnGPIO.Pull  = GPIO_NOPULL;
	btnGPIO.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &btnGPIO);
}

/**
 * @brief  EXTI Line Detection Callback
 * @param  GPIO_Pin Pin connected to EXTI Line
 * @retval None
 *
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == USER_BUTTON_PIN) {
		GPIO_PinState state = HAL_GPIO_ReadPin(USER_BUTTON_GPIO_PORT, \
						                       USER_BUTTON_PIN);
		if (state == GPIO_PIN_RESET) {
			should_blink = true;
		} else {
			should_blink = false;
		}


	}
}


