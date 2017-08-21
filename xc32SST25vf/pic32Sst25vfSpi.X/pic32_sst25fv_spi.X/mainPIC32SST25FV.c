/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/
#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <plib.h>           /* Include to use PIC32 peripheral libraries      */
#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */

#include "system.h"         /* System funct/params, like osc/periph config    */
#include "user.h"           /* User funct/params, such as InitApp             */
#include "SST25VF016.h"
#include "uart2.h"
#include "Compiler.h"
#include "drv_spi.h"
#include "HardwareProfile.h"
/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint32_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int32_t main(void)
{
const DRV_SPI_INIT_DATA SPI_Init_Data = {SST25_SPI_CHANNEL, 1, 0, 0, 1, 1, 0};

    DDPCONbits.JTAGEN = 0;

    SYSTEMConfig(SYS_FREQ, SYS_CFG_ALL); 

    /* Initialize I/O and Peripherals for application */
    InitApp();
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
    UART2Init(); 
    SST25Init((DRV_SPI_INIT_DATA *)&SPI_Init_Data);
    while(1)
    {

    }
}
