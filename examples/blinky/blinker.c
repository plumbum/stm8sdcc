#include "stm8s.h"
#include "stm8s_gpio.h"
#include "stm8s_beep.h"

static void delay(uint32_t t)
{
    while(t--);
}

int main( void )
{
    GPIOD->DDR |= GPIO_PIN_3; //  | GPIO_PIN_4;
    GPIOD->CR1 |= GPIO_PIN_3; //  | GPIO_PIN_4;
    GPIOD->ODR |= GPIO_PIN_3;

    BEEP_Init(BEEP_FREQUENCY_1KHZ);
    
    while(1)
    {
        delay(30000);
        GPIOD->ODR ^= GPIO_PIN_3; // | GPIO_PIN_4;
        BEEP_Cmd(ENABLE);
        delay(3000);
        BEEP_Cmd(DISABLE);
        delay(3000);
        BEEP_Cmd(ENABLE);
        delay(3000);
        BEEP_Cmd(DISABLE);
    }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
    (void)file;
    (void)line;
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
