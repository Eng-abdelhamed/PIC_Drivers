/* 
 * File:   application.h
 * Author: abdel
 *
 * Created on August 11, 2024, 2:14 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#define _XTAL_FREQ 4000000

#include"ECU_layer/LED/LED.h"
#include"ECU_layer/Button/Button.h"
#include"MCAL_layer/GPIO/hal_gpio.h"


void init(void);
void init2(void);
void init3(void);

void buttons(void);
void application_init(void);
void reading(void);
#endif	/* APPLICATION_H */

