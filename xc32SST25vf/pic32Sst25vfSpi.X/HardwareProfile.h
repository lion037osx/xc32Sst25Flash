/* 
 * File:   HardwareProfile.h
 * Author: optimus
 *
 * Created on 18 de julio de 2017, 21:08
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "system.h"
/*************************      CONFIG  ALL    ***********************************/
    
#define __WRITE_LOGO__    
    
#define CANT_DATA_READ     32
//#if defined(__WRITE_LOGO__    )    
#define HEADER_BMP    6
#define WIDTH 480
#define HEIGHT 272
#define STRLEN_WORD 2    
    
#define SIZE_LOGO ((WIDTH*HEIGHT*STRLEN_WORD)+HEADER_BMP)    //260087    
//#endif



    
/************************   Config spi for SST25FV016    ****************************/
    
#define SPI_CHANNEL_2_ENABLE   
    
#define USE_SST25_SPI2
    
#define USE_SST25VF016

#define SST25_CS_TRIS TRISDbits.TRISD1
    
#define GFX_EXPLORER16

#define SST25_SPI_CHANNEL 2
    
#define SST25_CS_LAT    LATDbits.LATD1
    
#if defined (USE_SST25VF016)
    #define FLASHInit(initData)             SST25Init(initData);
	#define ChipErase()                     SST25ChipErase();
	#define WriteArray(address, pdata, len) SST25WriteArray(address, pdata, len)
    #define ReadArray(address, pdata, len)  SST25ReadArray(address, pdata, len)
#endif	    
    
#define INPUT 1
#define OUTPUT 0    
#define PUSH 0   
#define BUTTON_TRIS TRISBbits.TRISB4
#define BUTTON_STAT PORTBbits.RB4    

/***************************
 configs pins
 sst25 CE-pin1 to RD1 -CS
 sst25 SDO-pin2 to RG7 -SDI
 sst25 SDI-pin5 to RG8 -SDO
 sst25 SCK-pin6 to RG6 -SCK
 ***************************/
    
#define BAUDRATE2       115200UL
#define BRG_DIV2        8 
#define BRGH2           0 
    
#define TX_TRIS		TRISFbits.TRISF5
#define RX_TRIS 	TRISFbits.TRISF4

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

