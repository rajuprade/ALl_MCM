#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>


#include <sys/types.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <netdb.h>
#include <setjmp.h>
#include <signal.h>
#include<time.h>
#define DOMON_TIMEOUT  60000000  // 1.5m

#define CMS_IP "192.168.3.35"

#define WRPR_IP  "192.168.34.2"
#define WRPR_PORT  3005    
   
#define RESP_PORT  5000
#define RESP_IP  "192.168.3.35"

#define EVNT_PORT 5001
#define EVNT_IP  "192.168.3.35"
  
#define MON_PORT  19999
#define MON_IP   "192.168.3.35"
      
#define SUBSYS_ID "SimulatedSys"   // SimulatedSys if not defined
#define DEVICE_IP "192.168.37.2" 

typedef enum { reqPORT, resPORT, evntPORT, monPORT } serverPorts;



#define SERVER_ADDR    "192.168.34.2"  // Server for AB testing
#define SERVER_PORT    "3005"           // For 192.168.8.143

//#define SERVER_ADDR    "192.168.4.65"   // Server for FE System
//#define SERVER_PORT    "3000"           // For 192.168.4.65

/**** FIFO Definition for FECB ***/

#define FECB_FIFO "/tmp/fecmd_fifo"

#define RESP_FECB "/tmp/resp_fecb"

char *fecbfifo;
int fifo_fd;      /* FIF0 File Descriptor for writing FECB command, Which can be read by USb-RS485 program */ 

char *respfecb;
int resp_fecbfd;   





void decodeResponse();

float temp;

#define ERROR      (-1)

int resp_msg_cntr;
int resp_code;
char mcm_addr;




#define MAXDATA       	128
#define DATALEN       	64
#define MSGLEN		128


typedef enum { WRAPPER=10, INTERMEDIATE=11, FINAL=12, ASYNCH=13, ALARM=100 } EventEnum ;
typedef enum { SUCCESS=10, FAILED=11, SYNTX=12, INCOMPLETE=13, INVALID=14, UNKNOWNERR=100 } CodeEnum ;



char temp_ar[20], time_ar[20] ;



#pragma pack(push,1)
typedef struct
 {
    short  id;
    short  level;
    char description[MSGLEN];
 } RespAlarm;

typedef struct
 {
    short numpkt;
    char prmname[MAXDATA][DATALEN];
    char prmvalue[MAXDATA][DATALEN];
 } DataPkt;

// Basic Fields Information resued by XMLIB to form XML ACK/NACK/RESPONSE //
typedef struct
 {
    int  seq;                  // Sequence number of Command
    float version;
    short priority ;
    short timeout ;
    char  subsysid[DATALEN];
    char  cmd_name[DATALEN];        // Command name at user level
    char  timestamp[DATALEN];
    char  cmd_id[8];           // Command ID Device Specific
 } BasicFlds;

typedef struct
 {
    short code;
    short event ;
    char message[MSGLEN];

    RespAlarm MCM_alarm;
    DataPkt resp_data;
    BasicFlds resp_elem;
 } devResponse;

typedef struct
 {
    BasicFlds cmdelem;
    DataPkt cmd_data;
 } parseCMSCmd;
#pragma pack(pop)
#define parseCMSCmdSize  sizeof(parseCMSCmd)
#define devResponseSize  sizeof(devResponse)

parseCMSCmd ser_Cmd;
devResponse dev_Resp, femonPkt;

#endif

//********************************************************************************************//
