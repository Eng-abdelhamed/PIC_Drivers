/* 
 * File:   hal_gpio.c
 * Author: abdelhamed
 *
 * Created on August 11, 2024, 1:33 PM
 */

#include"hal_gpio.h"

volatile uint8*TRIS_register[]={&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
volatile uint8*LAT_register[]={&LATA,&LATB,&LATC,&LATD,&LATE};
volatile uint8*PORT_register[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};

/**
 * @param _pin_config
 * @return 
 */
STD_TeturnType gpio_pin_intialize(const Pin_config *_pin_config){
    STD_TeturnType ret = E_OK;
    if(_pin_config == NULL)
    {
        ret =E_NOK;
    }
    else
    {
        gpio_pin_direction_init(_pin_config);
        gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
    return ret;
}
/**
 * @param _PI   N_
 * @return 
 */
STD_TeturnType gpio_pin_direction_init (const Pin_config *_PIN_)
{
    STD_TeturnType ret = E_OK;
    if(_PIN_ == NULL || _PIN_ ->pin_num > PIN_MAX_NUMBER -1)
    {
        ret = E_NOK;
    }
    else
    {
      switch(_PIN_->direction)
    {
        case Output:
            CLR_BIT(*TRIS_register[_PIN_->port],_PIN_->pin_num);
        break;
        case input:
             SET_BIT(*TRIS_register[_PIN_->port],_PIN_->pin_num);    
        break;
        default:
           ret = E_NOK; 
    }  
    }
    return ret;
}
/**
 * 
 * @param _PIN_
 * @param dic_status
 * @return 
 */
STD_TeturnType gpio_get_pin_direction_status(const Pin_config *_PIN_,direction_t *dic_status)
{
        STD_TeturnType ret = E_OK;
        if(_PIN_ == NULL ||dic_status == NULL)
        {
            ret = E_NOK;
        }
        else
        {
            *dic_status = GET_BIT(*TRIS_register[_PIN_->port],_PIN_->pin_num);
        }
        return ret;
}
/**
 * 
 * @param _PIN_
 * @param logic
 * @return 
 */
STD_TeturnType gpio_pin_write_logic(const Pin_config *_PIN_,Logic_t logic)
{
       STD_TeturnType ret = E_OK;
        if(_PIN_ == NULL ||_PIN_->pin_num > PIN_MAX_NUMBER-1)
        {
            ret = E_NOK;
        }
        else
        {
            switch(logic)
            {
                case high:
                    SET_BIT(*LAT_register[_PIN_->port],_PIN_->pin_num);
                    break;
                case low:
                    CLR_BIT(*LAT_register[_PIN_->port],_PIN_->pin_num);
                    break;
                default:
                    ret = E_NOK;
            }
        }
        return ret;
}
/**
 * 
 * @param _PIN_
 * @param logic
 * @return ?E_OK -> successfuly
 * E_NOK ->not successfuly
 */
STD_TeturnType gpio_pin_read_logic(const Pin_config *_PIN_,Logic_t *logic)
{
       STD_TeturnType ret = E_OK;
        if(_PIN_ == NULL ||logic == NULL)
        {
            ret = E_NOK;
        }
        else
        {
         *logic = GET_BIT(*PORT_register[_PIN_->port],_PIN_->pin_num);
        }
        return ret;
}
/**
 * 
 * @param _PIN_
 ** @return ?E_OK -> successfuly
 * E_NOK ->not successfuly
 */
STD_TeturnType gpio_pin_toggle_logic(const Pin_config *_PIN_)
{
       STD_TeturnType ret = E_OK;
        if(_PIN_ == NULL)
        {
            ret = E_NOK;
        }
        else
        {
            TOG_BIT(*LAT_register[_PIN_->port],_PIN_->pin_num);
        }
        return ret;
}
/**
 * 
 * @param _PORT_
 * @param direction
 * * @return ?E_OK -> successfuly
 * E_NOK ->not successfuly
 */
STD_TeturnType gpio_port_direction_init (PORT_INDEX_T _PORT_,uint8 direction)
{
       STD_TeturnType ret = E_OK;
       if(_PORT_ > PORT_MAX_NUMBER-1)
       {
           ret = E_NOK;
       }
       else
       { 
           *TRIS_register[_PORT_] = direction;
       }
        return ret;
}
/**
 * 
 * @param _Port_
 * @param direction_status
 * * @return ?E_OK -> successfuly
 * E_NOK ->not successfuly 
 */
STD_TeturnType gpio_get_port_direction_status(PORT_INDEX_T _Port_,uint8*direction_status)
{
       STD_TeturnType ret = E_OK;
       if(_Port_ >PORT_MAX_NUMBER -1 || direction_status == NULL)
       {
           ret = E_NOK;
       }
       else
       {
           *direction_status = *TRIS_register[_Port_];
       }
        return ret;
}
/**
 * 
 * @param _Port_
 * @param logic
 * * @return ? E_OK -> successfuly
 *             E_NOK ->not successfuly 
 */
STD_TeturnType gpio_port_write_logic(PORT_INDEX_T _Port_,uint8 logic)
{
       STD_TeturnType ret = E_OK;
       if(_Port_ > PORT_MAX_NUMBER -1)
       {
           ret = E_NOK;
       }
       else
       {
           *LAT_register[_Port_] = logic ;
       }
        return ret;
}
/**
 * 
 * @param _Port_
 * @param logic
 * * @return ?E_OK -> successfuly
 * E_NOK ->not successfuly
 */
STD_TeturnType gpio_port_read_logic(PORT_INDEX_T _Port_,uint8*logic)
{
       STD_TeturnType ret = E_OK;
       if(_Port_ > PORT_MAX_NUMBER -1 || logic == NULL)
       {
           ret = E_NOK;
       }
       else
       {
           *logic = *LAT_register[_Port_];
       }
    return ret;
}
/**
 * @param _Port_
 * @return 
 */
STD_TeturnType gpio_port_toggle_logic(PORT_INDEX_T _Port_)
{
       STD_TeturnType ret = E_OK;
       if(_Port_ > PORT_MAX_NUMBER -1)
       {
           ret = E_NOK;
       }
       else
       {
           *LAT_register[_Port_] ^= 0xFF; // Toggle all bits in the port
       }
        return ret;
}
