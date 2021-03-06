/*
 *
*/

#ifndef __NMP_MSG_H__
#define __NMP_MSG_H__

#include "nmp_message.h"
#include "nmp_share_struct.h"
#include "nmp_res_ctl.h"
#include "nmp_wdd.h"
#include "nmp_tw_interface.h"

typedef enum
{
    MSG_AUTHORIZATION_EXPIRED = 1,
    MSG_ALARM = 2,
    MSG_DEV_GU_OVER = 3,
    MSG_WDD_INEXISTENT = 4,
    MSG_SYSTEM_TIME_ERROR = 5,
    MSG_DEL_GU = 6,
    MSG_WDD_EOPEN_ERROER = 7,
    MSG_WDD_FORBIDDEN = 8,
    MSG_MSS_STATE_CHANGE = 9,
    MSG_WDD_ABNORMAL = 10
}NmpCuNotifyMsg;

/*
 * <MSG-001>
 *
 * MOD-CU => MOD-DBS
 * -> @user_name
 * <- @user_password, @user_group_id
*/
#define MSG_GET_USER_INFO			(MSG_INTERNAL_BASE + 1)
typedef struct _NmpMsgUserInfo NmpMsgUserInfo;
struct _NmpMsgUserInfo
{
    gchar			name[USER_NAME_LEN];
};

typedef struct _NmpMsgUserInfoRes NmpMsgUserInfoRes;
struct _NmpMsgUserInfoRes
{
    NmpMsgErrCode 	code;
    gchar			name[USER_NAME_LEN];
    gchar			passwd[USER_PASSWD_LEN];
    gint			   group_id;
};


/* <MSG-002>
 *
*/
#define MSG_GET_USER_GROUP_INFO		(MSG_INTERNAL_BASE + 2)
typedef struct _NmpMsgUserGroupInfo NmpMsgUserGroupInfo;
struct _NmpMsgUserGroupInfo
{
    gint			group_id;
};

typedef struct _NmpMsgUserGroupInfoRes NmpMsgUserGroupInfoRes;
struct _NmpMsgUserGroupInfoRes
{
    NmpMsgErrCode 	code;
    gint			group_id;
    guint		permission;
    gint			rank;
};


/* <MSG-003>
 *
*/
#define MSG_GET_USER_LOGIN_INFO		(MSG_INTERNAL_BASE + 3)
typedef struct _NmpMsgUserLoginInfo NmpMsgUserLoginInfo;
struct _NmpMsgUserLoginInfo
{
	gint			group_id;
};

typedef struct _NmpMsgUserLoginInfoRes NmpMsgUserLoginInfoRes;
struct _NmpMsgUserLoginInfoRes
{
    NmpMsgErrCode 	code;
    gchar			domain_id[DOMAIN_ID_LEN];
    gchar		 	domain_name[DOMAIN_NAME_LEN];
    gint			       root_area_id;
    gchar			root_area_name[AREA_NAME_LEN];
};

/* <MSG-004>
 *
*/
#define MSG_GET_MDS_IP		(MSG_INTERNAL_BASE + 4)
typedef struct _NmpMsgGetMdsIp NmpMsgGetMdsIp;
struct _NmpMsgGetMdsIp
{
    gchar			domain_id[DOMAIN_ID_LEN];
    gchar			puid[MAX_ID_LEN];
    gchar			cms_ip[MAX_IP_LEN];
};

typedef struct _NmpMsgGetMdsIpRes NmpMsgGetMdsIpRes;
struct _NmpMsgGetMdsIpRes
{
    NmpMsgErrCode 	code;
    gchar			mds_ip[MAX_IP_LEN];
    gchar                    mds_id[MDS_ID_LEN];
    gshort         rtsp_port;
};

typedef struct _NmpMsgGetUrl NmpMsgGetUrl;
struct _NmpMsgGetUrl
{
    NmpMsgErrCode 	code;
    gchar                    session[SESSION_ID_LEN];
    gchar			domain_id[DOMAIN_ID_LEN];
    gchar			guid[MAX_ID_LEN];
    gchar			mss_id[MSS_ID_LEN];
    gshort                   rtsp_port;
    gchar                    mds_id[MDS_ID_LEN];
    gchar			mds_ip[MAX_IP_LEN];
    gchar			cms_ip[MAX_IP_LEN];
    gint                       media;
    gchar              username[USER_NAME_LEN];
};


/* <MSG-005>
 *
*/
#define MSG_DEL_USER  	(MSG_INTERNAL_BASE + 5)
typedef struct _NmpMsgDelUser   NmpMsgDelUser;
struct _NmpMsgDelUser
{
    gchar			name[MULTI_NAME_LEN];
};

/* <MSG-006>
 *
*/
#define MSG_MODIFY_USER  	(MSG_INTERNAL_BASE + 6)
typedef struct _NmpMsgModifyUser   NmpMsgModifyUser;
struct _NmpMsgModifyUser
{
    gchar		name[USER_NAME_LEN];
    gint			group_id;
};

/* <MSG-007>
 *
*/
#define MSG_DEL_USER_GROUP  	(MSG_INTERNAL_BASE + 7)
typedef struct _NmpMsgDelUserGroup   NmpMsgDelUserGroup;
struct _NmpMsgDelUserGroup
{
    gchar group_ids[MULTI_NAME_LEN];
    gint group_permissions;
    gint  group_rank;
};

/* <MSG-008>
 *
*/
#define MSG_MSS_ONLINE_CHANGE  	(MSG_INTERNAL_BASE + 8)
typedef struct _NmpMsgMssOnlineChange   NmpMsgMssOnlineChange;
struct _NmpMsgMssOnlineChange
{
    gchar         mss_id[MSS_ID_LEN];
    gint           new_status;   //mss online status
    gchar         mss_ip[MAX_IP_LEN];
};

/* <MSG-009>
 *
*/
#define MSG_MDS_ONLINE_CHANGE  	(MSG_INTERNAL_BASE + 9)
typedef struct _NmpMsgMdsOnlineChange   NmpMsgMdsOnlineChange;
struct _NmpMsgMdsOnlineChange
{
    gchar         mds_id[MDS_ID_LEN];
    gint           new_status;   //mds online status
};

/* <MSG-0010>
 *
*/
#define MSG_GET_PARENT_DOMAIN		(MSG_INTERNAL_BASE + 10)

typedef struct _NmpMsgParentDomainInfo NmpMsgParentDomainInfo;
struct _NmpMsgParentDomainInfo
{
    gchar                domain_id[DOMAIN_ID_LEN];
    gchar			domain_ip[MAX_IP_LEN];
    gshort               port;
};

typedef struct _NmpMsgGetParentDomainRes NmpMsgGetParentDomainRes;
struct _NmpMsgGetParentDomainRes
{
    NmpMsgErrCode 	code;
    gint total_num;
    NmpMsgParentDomainInfo domain_info[0];
};

/* <MSG-0011>
 *
*/
#define MSG_CHECK_SUB_DOMAIN		(MSG_INTERNAL_BASE + 11)

typedef struct _NmpMsgSubDomainInfo NmpMsgSubDomainInfo;
struct _NmpMsgSubDomainInfo
{
    gchar                domain_id[DOMAIN_ID_LEN];
};

typedef struct _NmpMsgSubDomainRes NmpMsgSubDomainRes;
struct _NmpMsgSubDomainRes
{
    NmpMsgErrCode 	code;
};

/* <MSG-0012>
 *
*/
#define MSG_GET_DEVICE_MANUFACT		(MSG_INTERNAL_BASE + 12)

typedef struct _NmpMsgGetManufact NmpMsgGetManufact;
struct _NmpMsgGetManufact
{
    gchar                mf_id[MF_ID_LEN];
};

typedef struct _NmpMsgGetManufactRes NmpMsgGetManufactRes;
struct _NmpMsgGetManufactRes
{
    NmpMsgErrCode 	code;
    gchar                mf_name[MF_NAME_LEN];
};

#define MSG_AUTH_EXPIRED (MSG_INTERNAL_BASE + 12)

#define MSG_ALARM_COUNT_OVER (MSG_INTERNAL_BASE + 13)
typedef struct _NmpAlarmOver NmpAlarmOver;
struct _NmpAlarmOver
{
    gint	alarm_num;  // 可存储的最大告警数
};

/* <MSG-014>
 *
*/
#define MSG_AMS_ONLINE_CHANGE  	(MSG_INTERNAL_BASE + 14)
typedef struct _NmpMsgAmsOnlineChange   NmpMsgAmsOnlineChange;
struct _NmpMsgAmsOnlineChange
{
    gchar         ams_id[AMS_ID_LEN];
    gint           new_status;   //ams online status
};


/*
 * <MSG-015>
 */
#define MAX_AMS_ACTION_NUM	(20)
typedef enum
{
	AMS_ACTION_RECORD	= 0,
	AMS_ACTION_IO,
	AMS_ACTION_STEP,
	AMS_ACTION_PRESET,
	AMS_ACTION_SNAPSHOT,
	AMS_ACTION_MAP,
	AMS_ACTION_END,
	AMS_ACTION_MAX		= MAX_AMS_ACTION_NUM
} NmpAmsActionType;


/********************** action_record **********************/

typedef struct _NmpMsgActionRecordGu NmpMsgActionRecordGu;
struct _NmpMsgActionRecordGu
{
	NmpShareGuid	action_guid;
	gint			level;
	guint		time_len;
	guint		alarm_type;	//1,2,4,8...	或关系
	guint		mss_count;
	NmpShareMssId		mss_id[AMS_MAX_MSS_COUNT];
};

typedef struct _NmpMsgActionRecord NmpMsgActionRecord;
struct _NmpMsgActionRecord
{
	guint			action_gu_count;
	NmpMsgActionRecordGu	action_gu[0];
};

/********************** action_io **********************/

typedef struct _NmpMsgActionIOGu NmpMsgActionIOGu;
struct _NmpMsgActionIOGu
{
	NmpShareGuid	action_guid;
	guint		time_len;
	guint		alarm_type;	//1,2,4,8...	或关系
	gchar		io_value[IO_VALUE_LEN];
};

typedef struct _NmpMsgActionIO NmpMsgActionIO;
struct _NmpMsgActionIO
{
	guint			action_gu_count;
	NmpMsgActionIOGu	action_gu[0];
};

/********************** action_step **********************/

typedef struct _NmpMsgActionStepGu NmpMsgActionStepGu;
struct _NmpMsgActionStepGu
{
	guint	alarm_type;	//1,2,4,8...	或关系
	gint		tw_id;							//电视墙id
	gint		screen_id;						//显示屏id
	gint		division_id;						//分屏模式
	gint		division_num;					//分割号
	gchar	ec_name[TW_MAX_VALUE_LEN];	//编码器名称
	gchar	ec_domain_id[TW_ID_LEN];		//编码器所在的域id
	gchar	ec_guid[TW_ID_LEN];				//编码器guid
	gint		level;
};

typedef struct _NmpMsgActionStep NmpMsgActionStep;
struct _NmpMsgActionStep
{
	guint			action_gu_count;
	NmpMsgActionStepGu	action_gu[0];
};

/********************** action_preset **********************/

typedef struct _NmpMsgActionPresetGu NmpMsgActionPresetGu;
struct _NmpMsgActionPresetGu
{
	NmpShareGuid	action_guid;
	gint			preset_num;
	guint		alarm_type;	//1,2,4,8...	或关系
};

typedef struct _NmpMsgActionPreset NmpMsgActionPreset;
struct _NmpMsgActionPreset
{
	guint			action_gu_count;
	NmpMsgActionPresetGu	action_gu[0];
};

/********************** action_snapshot **********************/

typedef struct _NmpMsgActionSnapshotGu NmpMsgActionSnapshotGu;
struct _NmpMsgActionSnapshotGu
{
	NmpShareGuid	action_guid;
	gint			level;
	guint		picture_count;
	guint		alarm_type;	//1,2,4,8...	或关系
	guint		mss_count;
	NmpShareMssId		mss_id[AMS_MAX_MSS_COUNT];
};

typedef struct _NmpMsgActionSnapshot NmpMsgActionSnapshot;
struct _NmpMsgActionSnapshot
{
	guint			action_gu_count;
	NmpMsgActionSnapshotGu	action_gu[0];
};


/********************** action_map **********************/

typedef struct _NmpMsgActionMapGu NmpMsgActionMapGu;
struct _NmpMsgActionMapGu
{
	NmpShareGuid	action_guid;
	gchar			gu_name[GU_NAME_LEN];
	guint	alarm_type;	//1,2,4,8...	或关系
	gint		map_id;						//地图id
	gchar 		map_name[MAP_NAME_LEN];
	gint		level;
};

typedef struct _NmpMsgActionMap NmpMsgActionMap;
struct _NmpMsgActionMap
{
	NmpShareGuid	action_guid;
	gchar			gu_name[GU_NAME_LEN];
	gint			defence_id;
	gchar			defence_name[AREA_NAME_LEN];
	gint			map_id;
	gchar 			map_name[MAP_NAME_LEN];
	guint			action_gu_count;
	NmpMsgActionMapGu	action_gu[AMS_MAX_LINK_MAP_GU];
	gint				cu_count;
	NmpAllCuOwnPu		cu_list[0];
};

#define MSG_AMS_GET_ACTION_INFO	(MSG_INTERNAL_BASE + 15)
typedef struct _NmpMsgAmsGetActionInfo NmpMsgAmsGetActionInfo;
struct _NmpMsgAmsGetActionInfo
{
	NmpShareGuid		alarm_guid;
};

typedef struct _NmpMsgAmsGetActionInfoRes NmpMsgAmsGetActionInfoRes;
struct _NmpMsgAmsGetActionInfoRes
{
	int					result;
	NmpActionPolicy		action_policy;
	void					*actions[MAX_AMS_ACTION_NUM];
};

typedef enum _WddTimeType WddTimeType;
enum _WddTimeType
{
	WDD_AUTH_DATE = 0,
	WDD_AUTH_TIME_LEFT,
	WDD_AUTH_FOREVER,
	WDD_AUTH_NO_SOFTDOG,
	WDD_AUTH_OVERDUE
} ;

#define MSG_WDD_DEV_CAP_INFO	(MSG_INTERNAL_BASE + 16)
typedef struct _NmpMsgWddDevCapInfo NmpMsgWddDevCapInfo;
struct _NmpMsgWddDevCapInfo
{
	guint version;
	guint module_bits;
	guint modules_data[MODULES_MAX];
	NmpExpiredTime expired_time;
	guint max_dev;		/* 允许接入的最大设备个数 */
	guint max_av;		/* 音视频点最大个数, LIMIT_MAX代表无限制 */
	guint max_ds;		/* 显示通道最大个数 */
	guint max_ai;		/* 告警输入探头最大个数 */
	guint max_ao;		/* 告警输出探头最大个数 */
};


#define MSG_WDD_AUTH_ERROR	(MSG_INTERNAL_BASE + 17)
typedef enum
{
	WDD_AUTH_EXPIRED = 0,
	WDD_AUTH_INEXISTENT,
	WDD_SYS_TIME_ERROR
} WDD_AUTH_ERROR_TYPE;

typedef struct _NmpMsgWddAuthErrorInfo NmpMsgWddAuthErrorInfo;
struct _NmpMsgWddAuthErrorInfo
{
	guint type;	//WDD_AUTH_EXPIRED or WDD_AUTH_INEXISTENT or WDD_SYS_TIME_ERROR
};

#define MSG_CHANGE_LINK_TIME_POLICY	(MSG_INTERNAL_BASE + 18)

#define MSG_LOG_SET_SYSTEM_TIME		(MSG_INTERNAL_BASE + 19)

#define MSG_LOG_SET_NETWORK_CONFIG	(MSG_INTERNAL_BASE + 20)

#define MSG_LOG_PLATFORM_UPGRADE		(MSG_INTERNAL_BASE + 21)

#define MSG_LINK_RUN_STEP				(MSG_INTERNAL_BASE + 22)

#define MSG_DEL_ALARM_LINK				(MSG_INTERNAL_BASE + 23)

/* <MSG-024>
 *
*/
#define MSG_IVS_ONLINE_CHANGE  		(MSG_INTERNAL_BASE + 24)
typedef struct _NmpMsgIvsOnlineChange   NmpMsgIvsOnlineChange;
struct _NmpMsgIvsOnlineChange
{
    gchar         ivs_id[IVS_ID_LEN];
    gint           new_status;   //ivs online status
    gchar         ivs_ip[MAX_IP_LEN];
};

#define MSG_CHECK_MSS_STATE			(MSG_INTERNAL_BASE + 25)

#define MSG_PU_RECHECK					(MSG_INTERNAL_BASE + 26)


#define __MSG_INTERNAL_TW_BASE			(MSG_INTERNAL_BASE + 100)

#define MSG_TW_INFO_GET_TOUR				(__MSG_INTERNAL_TW_BASE)
#define MSG_TW_INFO_GET_GROUP			(__MSG_INTERNAL_TW_BASE + 1)
#define MSG_TW_INFO_GET_GROUP_STEP_N		(__MSG_INTERNAL_TW_BASE + 2)
#define MSG_TW_INFO_GET_DIS_GUID			(__MSG_INTERNAL_TW_BASE + 3)
#define MSG_TW_INFO_GET_EC_URL			(__MSG_INTERNAL_TW_BASE + 4)
#define MSG_TW_INFO_CHECK_EC_URL_UPDATE		(__MSG_INTERNAL_TW_BASE + 5)
#define MSG_TW_INFO_NOTIFY_UPDATE_EC_URL	(__MSG_INTERNAL_TW_BASE + 6)


#endif	//__NMP_MSG_H__
