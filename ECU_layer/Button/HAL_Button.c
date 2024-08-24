/* 
 * File:   led.c
 * Author: abdelhamed
 *
 * Created on August 11, 2024, 1:33 PM
 */

#include"Button.h"


STD_TeturnType Button_INIT(const Button_t*Button)
{
    uint8 Return_State = E_OK;
    if(Button == NULL)
    {
        Return_State = E_NOK;
    }
    else
    {
        Return_State = gpio_pin_direction_init(&Button->Button_Pin);
    }
    return Return_State;
}
STD_TeturnType Button_Read_State(const Button_t*Button, Button_State *BtnState)
{
    uint8 Return_State = E_OK;
    Logic_t Status = low;
    if(Button == NULL || BtnState == NULL)
    {
        Return_State = E_NOK;
    }
    else
    {
        gpio_pin_read_logic(&(Button->Button_Pin),&Status);
        if(Button_Active_High == Button->Button_Activate)
        {
            if(high == Status)
            {
                *BtnState = Button_pressed;
            }
            else
            {
                *BtnState = Button_NotPressed;
            }
        }
        else if(Button_Active_low == Button->Button_Activate)
        {
            if(high == Status)
            {
                *BtnState = Button_NotPressed;
            }
            else
            {
                *BtnState = Button_pressed;
            }
        }
        else
        {
         /**
          * nothing
          */   
        }
        Return_State =E_OK;
    }
return Return_State;
}