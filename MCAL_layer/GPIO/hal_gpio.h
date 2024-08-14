/* 
 * File:   hal_gpio.h
 * Author: abdelhamed
 * Created on August 11, 2024, 1:49 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/*SECTION : Includes*/
#include"pic18f4620.h"
#include"../mcal_std_types.h"
#include"../../MCAL_layer/device_config.h"

/*SECTION : macro declarations */

  

/*SECTION : function macro declarations */
#define PIN_MAX_NUMBER          8
#define PORT_MAX_NUMBER         5 


#define SET_BIT(REG , BIT_POS)     REG |=  (1<<BIT_POS)
#define CLR_BIT(REG , BIT_POS)     REG &= ~(1<<BIT_POS)
#define TOG_BIT(REG , BIT_POS)     REG ^=  (1<<BIT_POS)
#define GET_BIT(REG , BIT_POS)     ((REG>>BIT_POS) & 1)
/*SECTION : data type declarations */
typedef enum
{
    low = 0,
    high
}Logic_t;

typedef enum
{
    Output = 0,
    input
}direction_t;


typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7  
}pin_index_t;

typedef enum
{
    PORTA_INDEX = 0,
    PORTB_INDEX ,
    PORTC_INDEX ,
    PORTD_INDEX ,
    PORTE_INDEX 
}PORT_INDEX_T;

typedef struct
{
    uint8 port : 3;   // @ref PORT_INDEX_T
    uint8 pin_num : 3; // @ref pin_index_t
    uint8 direction : 1; // @ref direction_t
    uint8 logic : 1; // @ref Logic_t
}Pin_config;


/*SECTION : functions declarations */
STD_TeturnType gpio_pin_direction_init (const Pin_config *_PIN_);
STD_TeturnType gpio_pin_intialize(const Pin_config *_pin_config);
STD_TeturnType gpio_get_pin_direction_status(const Pin_config *_PIN_,direction_t *dic_status);
STD_TeturnType gpio_pin_write_logic(const Pin_config *_PIN_,Logic_t logic);
STD_TeturnType gpio_pin_read_logic(const Pin_config *_PIN_,Logic_t *logic);
STD_TeturnType gpio_pin_toggle_logic(const Pin_config *_PIN_);

STD_TeturnType gpio_port_direction_init (PORT_INDEX_T _PORT_,uint8 direction);
STD_TeturnType gpio_get_port_direction_status(PORT_INDEX_T _Port_,uint8*direction_status);
STD_TeturnType gpio_port_write_logic(PORT_INDEX_T _Port_,uint8 logic);
STD_TeturnType gpio_port_read_logic(PORT_INDEX_T _Port_,uint8*logic);
STD_TeturnType gpio_port_toggle_logic(PORT_INDEX_T _Port_);

#endif	/* HAL_GPIO_H */

