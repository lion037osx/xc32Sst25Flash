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
//#include "drv_spi.h"
#include "HardwareProfile.h"
#include "logo480.h"
//#include "TimeDelay.h"
/*
 typedef struct{
    int    channel;
	int	    baudRate;
	int     dummy;
	char    cke;
	char    ckp;
	char    smp;
	char    mode;
} DRV_SPI_INIT_DATA;
 */
int32_t main(void)
{
//const DRV_SPI_INIT_DATA SPI_Init_Data ={SST25_SPI_CHANNEL,16, 0, SPI_CKE_IDLE_ACT, SPI_CKP_ACT_LOW, SPI_SMP_PHASE_MID,SPI_MST_MODE_ENABLE};
static int tmp;
static char charTmp;
static char strTmp[40];       
DDPCONbits.JTAGEN = 0;
SYSTEMConfigPerformance(GetSystemClock());
/* Initialize I/O and Peripherals for application */
//InitApp();
//INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
//BUTTON_TRIS=INPUT;

TRISBbits.TRISB4=1;PORTSetPinsDigitalIn(IOPORT_B, BIT_4);

UART2Init(); 
//    SST25Init((DRV_SPI_INIT_DATA *)&SPI_Init_Data);

UART2PrintString("\r\nConfig Spi sst25vf init");

UART2PrintString("\r\n");    
SST25Init();

    static DWORD address=0x0000;
    static BYTE byteTmp;
  
    static char cByte;
static   char strSST[64];
    static DWORD sizeLogo;
    static int flagWrite=0;
    //sizeLogo=strlen(logo);
    
    //sizeLogo=0x3FC08;
   // sizeLogo=0x996C9;
    sizeLogo=SIZE_LOGO;
    sprintf(strSST,"size logo:%u,\r\n",sizeLogo);
    
  
UART2PrintString("\r\n"); 
UART2PrintString("init Write");
UART2PrintString("\r\n");    

cByte=0x20;
flagWrite=0;

while(BUTTON_STAT==PUSH)flagWrite=1;

if(flagWrite==1){
    UART2PrintString("\r\n"); 
UART2PrintString("init erase");
UART2PrintString("\r\n");   
//UART2PrintString(strSST);
SST25ChipErase();

UART2PrintString("\r\n"); 
UART2PrintString("end erase");
UART2PrintString("\r\n"); 
}


    while(flagWrite&&sizeLogo--) 
    {
        //if(cByte>=255)cByte=0x20;
        // if(address>0xffff)address=0x0000;
        SST25WriteByte(logo[address],address);
        //cByte++;
        address++;
    }
//sizeLogo=strlen(logo);
    //sizeLogo=0x3FC08;
    //sizeLogo=0x996C9;
sizeLogo=SIZE_LOGO;
UART2PrintString("\r\n"); 
UART2PrintString("end Write");
UART2PrintString("\r\n");    

sprintf(strSST,"size logo:%u,\r\n",sizeLogo);
UART2PrintString(strSST);

   // while(sizeLogo--) 
address=0x0000;
int byteReads=32;
for(byteReads=0;byteReads<64;byteReads++)
    {
       // if(address>0xffff)address=0x0000;
        byteTmp=SST25ReadByte(address);
        
        sprintf(strSST,"0x%X,",byteTmp);
        
     // if(byteTmp!=0x00) UART2PutChar(byteTmp);
       
       UART2PrintString(strSST);
        address++;
       
    }

UART2PrintString("\r\n"); 
UART2PrintString("end Read");
UART2PrintString("\r\n"); 
}

/***************************
 
 
 configs pins

 sst25 CE-pin1 to RD1 -CS
 sst25 SDO-pin2 to RG7 -SDI
 sst25 SDI-pin5 to RG8 -SDO
 sst25 SCK-pin6 to RG6 -SCK
 

 ******************************/




void f_interrupt(void){

SST25ReadByte(0xf0);
    
}