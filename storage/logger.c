#include <time.h>
#include "logger.h"

char* get_log_name(LOG_MODE logMode) {
	if (logMode == LOG_ALL)     return "ALL   |";
	if (logMode == LOG_DEBUG)   return "DEBUG |";
	if (logMode == LOG_ERROR)   return "ERROR |";
	if (logMode == LOG_FATAL)   return "FATAL |";
	if (logMode == LOG_INFO)    return "INFO  |";
	if (logMode == LOG_OFF)     return "OFF   |";
	if (logMode == LOG_TRACE)   return "TRACE |";
	if (logMode == LOG_WARN)    return "WARN  |";
	return NULL;
}

void LOG(Context *context, LOG_MODE mode, char* message) {
	if (context->mode == APP_DEVELOPMENT) {
		char *modeName = get_log_name(mode);
		fprintf(stdout, "\n%s %s", modeName, message);
		fflush(stdout);
	}
}

// Screen logger
void LOG_S(Context *context, char *format, char* message) {
	if (context->mode == APP_DEVELOPMENT) {
		fprintf(stdout, format, message);
		fflush(stdout);
	}
}

void LOG_D(Context *context, char* message) {
	LOG(context, LOG_DEBUG, message);
}

void LOG_I(Context *context, char* message) {
    LOG(context, LOG_INFO, message);
}

void LOG_E(Context *context, char* message) {
    LOG(context, LOG_ERROR, message);
}

void logger_write(const char *fmt, ...) {
    char buff[10240];
    va_list args;
    va_start(args, fmt);
    vsprintf(buff, fmt, args);
    buff[strlen(buff)] = '\0';

	char **param = string_split(buff, "|");
	if (strcmp(param[MODE_INDEX], LOG_APP_TEST) == 0) {
    	va_end(args);
    	return;
    }

    if (NULL == param[DATA_LOG_INDEX]) {
    	param[DATA_LOG_INDEX] = "";
    }

    char *query;
	asprintf(&query, "[worker]|%s|%s|%d|%s|%s|%d|%s|%s|%s|%ld\n",
		param[REQUEST_ID_INDEX], param[PROCESS_ORDER_INDEX], param[LEVEL_INDEX], param[FILE_INDEX], param[FUNCTION_INDEX],
		param[LINE_INDEX], param[SCOPE_INDEX], param[MESSAGE_INDEX], param[DATA_LOG_INDEX], param[TIMESTAMP_INDEX]);
	
	fprintf(stdout, "%s", query);
	fflush(stdout);

    free(param);
    free(query);
	va_end(args);
}
