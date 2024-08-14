/* 
 * File:   mcal_std_types.h
 * Author: abdel
 *
 * Created on August 11, 2024, 1:53 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*SECTION : Includes*/
#include"std_library.h"
#include"compilers.h"
/*SECTION : macro declarations */

#define STD_HIGH      0x01
#define STD_LOW       0x00

#define STD_ON        0x01
#define STD_OFF       0x00

#define STD_ACTIVE    0x01
#define STD_IDLE      0x00

/*SECTION : function macro declarations */



/*SECTION : data type declarations */
typedef unsigned char  uint8;
typedef unsigned int   uint32;
typedef unsigned short uint16;
typedef signed int     sint32;
typedef signed char    sint8;
typedef signed short   sint16;

typedef uint8 STD_TeturnType;

#define E_OK   (STD_TeturnType)0x01
#define E_NOK  (STD_TeturnType)0x00

/*SECTION : functions declarations */



#endif	/* MCAL_STD_TYPES_H */

