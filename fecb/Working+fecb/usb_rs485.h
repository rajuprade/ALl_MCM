
#ifndef USB_RS485_H_INCLUDED
#define USB_RS485_H_INCLUDED
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include<string.h>
#include <sys/io.h>       
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pthread.h>
#include<time.h>
#include<fcntl.h>
#include"/home/raj/Desktop/fecb/ftd2xx.h" 

void add_cksum(char buff[]);
void write_read(char *buff, char *buf_ptr0,serialBuff rbuff);
//#include"ftd2xx.h"

//FILE *f,*fp;
#define BUF_SIZE  0x10
unsigned char Arg[100];

#define DEVICE_ID "FT07T5Q2"


#endif
