#ifndef __CLIENT_INTER__
#define __CLIENT_INTER__

#include "nmp_afx.h"

#include "nmp_list_head.h"

#include "nmp_msg_share.h"


typedef struct _callback_function
{
	void (*proc_register)(void *, void *);
	void (*get_region_info)(void *, void *);	//区域
	void (*get_pu_info)(void *, void *);      //设备
	void (*get_gu_info)(void *, void *);		//业务点
}callback_function;



typedef enum
{
	DISCONNECTED,
	CONNECTING,
	CONNECTED,
	DISCONNECTING
}NmpConnState;


//注册以及连接状态信息
typedef struct _register_info{
	NmpNetIO	*bridge;		/* communication bridge */
	char damon_name[64];
	char damod_id[64];
	char ip[20];
	int port;
	GMutex		*lock;
	int unregistered;
	int state_timer;
	int seq_generator;
	NmpConnState state;
	struct _register_info *next;
}register_info;

//心跳信息
typedef struct _NmpHeart NmpHeart;
struct _NmpHeart
{
    gchar			 domain_id[USER_NAME_LEN];
};

typedef struct _NmpHeartResp NmpHeartResp;
struct _NmpHeartResp
{
    NmpMsgErrCode	code;
    //gchar			server_time[TIME_INFO_LEN];
};


//注册数据结构体(暂时用这个名称)
typedef struct _NmpClientLoginInfo NmpClientLoginInfo;
struct _NmpClientLoginInfo
{
	gchar domain_id[USER_NAME_LEN];
	//gchar password[USER_PASSWD_LEN];
};


typedef struct _NmpClientLoginRes NmpClientLoginRes;
struct _NmpClientLoginRes
{
    NmpMsgErrCode       code;
    //gchar       domain_name[DOMAIN_NAME_LEN];
    //gchar       domain_id[DOMAIN_ID_LEN];
};


typedef int (*PROC_REGISTER)(
	NmpClientLoginInfo *reg,
	NmpClientLoginRes *res_info
);


//初始化注册初始化函数
int nmp_proc_register_function_init(PROC_REGISTER registerfun);

//socket连接服务器端
int nmp_connect_to_server(register_info *node);

//心跳发送
int nmp_send_heartbeat(register_info *node);

//客户端关闭socket连接
int nmp_close_connect(register_info *node);

//客户端，获取注册所需信息函数
register_info *get_register_platform_info();

//客户端发起注册
int nmp_register_to_server(register_info *node);

//client端初始化
void nmp_client_mods_init(void);

int nmp_client_register_callback(callback_function *function);

int add_parent_domain(char *ip, int port, char *domain_id);

int del_parent_domain(char *domain_id);





#endif

