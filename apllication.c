/* 
 * File:   apllication.c
 * Author: abdelhamed
 *
 * Created on August 11, 2024, 1:33 PM
 */


#include"application.h"


Pin_config led_1={.port  =  PORTC_INDEX, .logic   =high  ,   .pin_num=  PIN0 ,.direction = Output};
Pin_config led_2={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num=  PIN1 ,.direction = Output};
Pin_config led_3={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN2 ,.direction  = Output};
Pin_config led_4={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN3 ,.direction  = Output};
Pin_config led_5={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN4 ,.direction  = Output};
Pin_config led_6={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN5 ,.direction  = Output};
Pin_config led_7={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN6 ,.direction  = Output};
Pin_config led_8={.port  =  PORTC_INDEX, .logic   =high   ,  .pin_num = PIN7 ,.direction  = Output};

Pin_config btn_1 ={.port =  PORTD_INDEX,  .logic  =high,     .pin_num = PIN0 ,.direction = input};
Pin_config btn_2 ={.port =  PORTD_INDEX,  .logic  =high,     .pin_num = PIN1 ,.direction = input};
Logic_t state;
Logic_t state1;
STD_TeturnType ret = E_NOK;
uint8 counter = 0;
int main() 
{ 
    gpio_pin_direction_init(&btn_1);
    gpio_pin_direction_init(&btn_2);
    while(1)
    {
        gpio_pin_read_logic(&btn_1 ,&state);
        gpio_pin_read_logic(&btn_2 ,&state1);
        if(state == 1)
        {
            init();
        }
        else if(state1 == 1)
        {
            init2();
        }
        else
        {
           gpio_port_direction_init(PORTC_INDEX,0xFF); 
        }
      
    }

    
    
    return (EXIT_SUCCESS);
}

void init(void)
{
    gpio_port_direction_init(PORTC_INDEX,0x00);
    gpio_pin_write_logic(&led_1,high);
    gpio_pin_write_logic(&led_2,high);
    gpio_pin_write_logic(&led_3,high);
    gpio_pin_write_logic(&led_4,high);
    gpio_pin_write_logic(&led_5,high);
    gpio_pin_write_logic(&led_6,high);
    gpio_pin_write_logic(&led_7,high); 
    gpio_pin_write_logic(&led_8,high); 
}
void init2(void)
{
    gpio_port_direction_init(PORTC_INDEX,0xAA);
    gpio_pin_write_logic(&led_1,high);
    gpio_pin_write_logic(&led_2,high);
    gpio_pin_write_logic(&led_3,high);
    gpio_pin_write_logic(&led_4,high);
    gpio_pin_write_logic(&led_5,high);
    gpio_pin_write_logic(&led_6,high);
    gpio_pin_write_logic(&led_7,high); 
    gpio_pin_write_logic(&led_8,high); 
}