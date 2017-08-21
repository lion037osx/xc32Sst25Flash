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
    
#define USE_SST25VF016   

#define SST25_SPI_CHANNEL 1
    
#define SST25_CS_LAT    LATDbits.LATD1
    
#define GetPeripheralClock() 80000000ul

#define BAUDRATE2       115200UL
#define BRG_DIV2        8 
#define BRGH2           0 
    
#define TX_TRIS		TRISFbits.TRISF5
#define RX_TRIS 	TRISFbits.TRISF4

    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

