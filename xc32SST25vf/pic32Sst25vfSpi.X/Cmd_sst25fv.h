/* 
 * File:   Cmd_sst25fv.h
 * Author: optimus
 *
 * Created on 19 de julio de 2017, 11:06
 */

#ifndef CMD_SST25FV_H
#define	CMD_SST25FV_H

#ifdef	__cplusplus
extern "C" {
#endif

#define READ_MEMORY_AT_25MHZ 0x03
#define READ_MEMORY_AT_80MHZ 0x0B
#define READ_MEMORY_HIGH_SPEED READ_MEMORY_AT_80MHZ
#define ERASE_SECTOR_4KB 0x20
#define ERASE_BLOCK_32KB 0x52     
#define ERASE_BLOCK_64KB 0xD8
#define CHIP_ERASE 0x60
#define BYTE_PROGRAM 0x02
#define ADDRESS_INCREMENT_PROG 0xAD
#define READ_STATUS_REGISTER 0x05 
#define RDSR READ_STATUS_REGISTER
#define ENABLE_WRITE_STATUS_REGISTER 0x50    
#define EWSR ENABLE_WRITE_STATUS_REGISTER
#define WRITE_STATUS_REGISTER 0x01
#define WRSR WRITE_STATUS_REGISTER

#define WRITE_ENABLE 0x06
#define WREN WRITE_ENABLE
#define WRITE_DISABLE 0x04
#define WRDI WRITE_DISABLE
#define READ_ID 0x90
#define RDID READ_ID  
    
    
    
    
    
    




#ifdef	__cplusplus
}
#endif

#endif	/* CMD_SST25FV_H */

