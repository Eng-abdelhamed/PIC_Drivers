/* 
 * File:   LED.h
 * Author: abdel
 *
 * Created on August 11, 2024, 1:59 PM
 */

#ifndef LED_H
#define	LED_H


/*SECTION : Includes*/
#include"../../MCAL_layer/GPIO/hal_gpio.h"
#include"LED_CONFIG.h"


/*SECTION : macro declarations */



/*SECTION : function macro declarations */



/*SECTION : data type declarations */
typedef enum
{
    LED_OFF = 0,
    LED_ONN
}LED_STATUS;

typedef struct
{
    uint8 PORT_NUM :4 ;
    uint8 PIN_NUM : 3;
    uint8 LED_STATUS : 1;
}LED_T;

/*SECTION : functions declarations */
STD_TeturnType LED_INITIALIZE(LED_T * LED);
STD_TeturnType LED_ON(LED_T * LED);
STD_TeturnType LED_OF(LED_T * LED);
STD_TeturnType LED_Toggle(LED_T * LED);
#endif	/* LED_H */

