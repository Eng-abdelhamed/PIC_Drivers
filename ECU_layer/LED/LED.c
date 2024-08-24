/* 
 * File:   led.c
 * Author: abdelhamed
 *
 * Created on August 11, 2024, 1:33 PM
 */
#include"LED.h"
/**
 * @param LED
 * @return 
 */
STD_TeturnType LED_INITIALIZE(LED_T * LED)
{
    uint8 Return_STatus = E_OK;
    if(LED == NULL)
    {
        Return_STatus = E_NOK;
    }
    else
    {
        Pin_config pin_obj={.port = LED->PORT_NUM , .pin_num = LED->PIN_NUM ,.logic = LED->LED_STATUS ,.direction = Output};
        gpio_pin_intialize(&pin_obj);
    }
    
    return Return_STatus;
}
/**
 * @param LED
 * @return 
 */
STD_TeturnType LED_ON(LED_T * LED)
{
     uint8 Return_STatus = E_OK;
    if(LED == NULL)
    {
        Return_STatus = E_NOK;
    }
    else
    {
       Pin_config pin_obj={.port = LED->PORT_NUM , .pin_num = LED->PIN_NUM ,.logic = LED->LED_STATUS ,.direction = Output};
       gpio_pin_write_logic(&pin_obj,high);
    }
    return Return_STatus;
}
/**
 * @param LED
 * @return 
 */
STD_TeturnType LED_OF(LED_T * LED)
{
     uint8 Return_STatus = E_OK;
    if(LED == NULL)
    {
        Return_STatus = E_NOK;
    }
    else
    {
       Pin_config pin_obj={.port = LED->PORT_NUM , .pin_num = LED->PIN_NUM ,.logic = LED->LED_STATUS ,.direction = Output};
       gpio_pin_write_logic(&pin_obj,low);
    }
    return Return_STatus;
}
/**
 * @param LED
 * @return 
 */
STD_TeturnType LED_Toggle(LED_T * LED)
{
    uint8 Return_STatus = E_OK;
    if(LED == NULL)
    {
        Return_STatus = E_NOK;
    }
    else
    {
       Pin_config pin_obj={.port = LED->PORT_NUM , .pin_num = LED->PIN_NUM ,.logic = LED->LED_STATUS ,.direction = Output};
       gpio_pin_toggle_logic(&pin_obj);
    }
    return Return_STatus;
}