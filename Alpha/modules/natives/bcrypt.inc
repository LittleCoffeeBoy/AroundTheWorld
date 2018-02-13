#if defined bcrypt_included
	#endinput
#endif
#define bcrypt_included

#if !defined HTTP_GET
	#include <natives/a_http>
#endif

#define BCRYPT_HASH_LENGTH 61
#define BCRYPT_PLUGIN_VERSION "2.2.3"

enum BCRYPT_DEBUG_LEVEL {
	BCRYPT_LOG_FATAL,
	BCRYPT_LOG_ERROR,
	BCRYPT_LOG_WARNING,
	BCRYPT_LOG_INFO,
	BCRYPT_LOG_DEBUG,
	BCRYPT_LOG_TRACE
}

native bcrypt_hash(key[], cost = 12, callback_name[], callback_format[] = "", {Float, _}:...);
native bcrypt_check(password[], hash[], callback_name[], callback_format[] = "", {Float, _}:...);
native bcrypt_get_hash(dest[]);
native bool:bcrypt_is_equal();
native bool:bcrypt_needs_rehash(hash[], cost);
native bcrypt_find_cost(time_target = 250);
native bcrypt_set_thread_limit(value);
native bcrypt_debug(BCRYPT_DEBUG_LEVEL:level = BCRYPT_LOG_ERROR);

// Version check
forward OnBcryptVersionCheck(index, response_code, data[]);

#if defined FILTERSCRIPT
	public OnFilterScriptInit()
	{
		HTTP(0, HTTP_GET, "api.ls-rcr.com/bcrypt/?version_check&version=" #BCRYPT_PLUGIN_VERSION, "", "OnBcryptVersionCheck");
		return CallLocalFunction("BCRYPT_OnFilterScriptInit", "");
	}

	forward BCRYPT_OnFilterScriptInit();

	#if defined _ALS_OnFilterScriptInit
	    #undef OnFilterScriptInit
	#else
	    #define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit BCRYPT_OnFilterScriptInit
#else
	public OnGameModeInit()
	{
		HTTP(0, HTTP_GET, "api.ls-rcr.com/bcrypt/?version_check&version=" #BCRYPT_PLUGIN_VERSION, "", "OnBcryptVersionCheck");
		return CallLocalFunction("BCRYPT_OnGameModeInit", "");
	}

	forward BCRYPT_OnGameModeInit();

	#if defined _ALS_OnGameModeInit
	    #undef OnGameModeInit
	#else
	    #define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit BCRYPT_OnGameModeInit
#endif

public OnBcryptVersionCheck(index, response_code, data[])
{
	return 1;
}