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
    
//Config spi for SST25FV016    
    
#define SPI_CHANNEL_2_ENABLE   
    
#define USE_SST25_SPI2
    
#define USE_SST25VF016

#define SST25_CS_TRIS TRISDbits.TRISD1
    
#define GFX_PICTAIL_V3

#define SST25_SPI_CHANNEL 2
    
#define SST25_CS_LAT    LATDbits.LATD1
    
    #if defined (USE_SST25VF016)
    #define FLASHInit(initData)             SST25Init(initData);
	#define ChipErase()                     SST25ChipErase();
	#define WriteArray(address, pdata, len) SST25WriteArray(address, pdata, len)
    #define ReadArray(address, pdata, len)  SST25ReadArray(address, pdata, len)
#endif	
    
    
    #if defined (USE_SST25VF016) 
//    #define FLASHInit()                     SST25Init();
#endif
#define INPUT 1
#define OUTPUT 0    
    
#define BUTTON_TRIS TRISBbits.TRISB4
#define BUTTON_STAT PORTBbits.RB4
    
#define PUSH 0
    
#define SIZE_LOGO ((480*272*2)+18)    //260087
//#define GetPeripheralClock() 80000000ul

#define BAUDRATE2       115200UL
#define BRG_DIV2        8 
#define BRGH2           0 
    
#define TX_TRIS		TRISFbits.TRISF5
#define RX_TRIS 	TRISFbits.TRISF4

    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

