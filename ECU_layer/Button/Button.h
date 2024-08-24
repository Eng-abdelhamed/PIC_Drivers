/* 
 * File:   Button.h
 * Author: abdel
 *
 * Created on August 21, 2024, 10:52 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include"../../MCAL_layer/GPIO/hal_gpio.h"

typedef enum
{
    Button_pressed = 0,
    Button_NotPressed
}Button_State;
typedef enum
{
    Button_Active_low = 0,
    Button_Active_High
}Button_Active;

typedef struct
{
    Pin_config Button_Pin;
    Button_State Button_State;
    Button_Active Button_Activate;
}Button_t;

/**
 * 
 * @param Button
 * @return STD_TeturnType
 */
STD_TeturnType Button_INIT(const Button_t*Button);
/**
 * @param Button
 * @param BtnState
 * @return STD_TeturnType
 */
STD_TeturnType Button_Read_State(const Button_t*Button, Button_State *BtnState);





#endif	/* BUTTON_H */

