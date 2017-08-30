/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
//void f_interrupt(void);
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2	
#pragma config FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL

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
#include "HardwareProfile.h"
#ifdef __WRITE_LOGO__
//#include "logo.h"
#include "logoIcon.h"
    //#include "logo480.h"
   // #include "domotics13_24bitsC32.h"
#endif

int32_t main(void)
{   
static DWORD address=0x0000;
static BYTE byteTmp;
static DWORD byteReads=CANT_DATA_READ;  
//static char cByte;
static char strSST[64];
static DWORD sizeLogo;
static int flagWrite;

DDPCONbits.JTAGEN = 0;
SYSTEMConfigPerformance(GetSystemClock());

TRISBbits.TRISB4=1;
PORTSetPinsDigitalIn(IOPORT_B,BIT_4);

UART2Init(); 
UART2PrintString("\r\nFirmware XC32 sst25vf\r\n");
   
SST25Init();

    sizeLogo=SIZE_LOGO;
    //sprintf(strSST,"size logo:%u,\r\n",sizeLogo);    
    //UART2PrintString("init Write\r\n");

    flagWrite=0;
    DWORD iSearch=0;
while(BUTTON_STAT==PUSH)flagWrite=1;
#ifdef __WRITE_LOGO__
    if(flagWrite==1){
        UART2PrintString("init erase\r\n");
        SST25ChipErase();
        UART2PrintString("end erase\r\n");
    }
UART2PrintString("init Write\r\n");    

WORD draw;
/*
while(flagWrite&&sizeLogo--) 
    {

draw=(WORD)(((domotics[iSearch+1]<<8)&0xFF00) | (domotics[iSearch] & 0xFF));            
    //draw=(WORD)(logo[iSearch]) | (logo[iSearch+1]<<8);
        SST25WriteWord(draw,address);
        iSearch=iSearch+2;
        address++;
    }

*/


 
 while(flagWrite&&sizeLogo--) 
    {
        //SST25WriteByte(domotics[address],address);
     SST25WriteByte(logo[address],address);
       address++;
    }
 

UART2PrintString("end Write\r\n");
#endif

sizeLogo=SIZE_LOGO;
address=0x0000;

    for(byteReads=0;byteReads<64;byteReads++)
    {
        byteTmp=SST25ReadByte(address);        
        sprintf(strSST,"0x%X,",byteTmp);
        UART2PrintString(strSST);
        address++;
    }
    UART2PrintString("\r\nend Read\r\n");
}

