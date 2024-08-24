/* 
 * File:   apllication.c
 * Author: abdelhamed
 *
 * Created on August 11, 2024, 1:33 PM
 */


#include"application.h"

Pin_config pin1={.direction = Output ,.logic =high ,.pin_num = PIN0 ,.port = PORTC_INDEX};
void main()
{
    gpio_pin_direction_init(&pin1);
    gpio_pin_write_logic(&pin1,high);
    
    
    
}