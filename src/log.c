#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <malloc.h>
#include "log.h"

Logger logger;

void InitLogger(LogLevel level, FILE *file)
{
	Logger *lptr = &logger;
	lptr->file = file;
	lptr->level = level;
	lptr->printErrToStderr = 0;
}
void PrintErrToStderr(int boolean) {
	Logger *lptr = &logger;
	lptr->printErrToStderr = boolean;
}


char *__TimeString()
{
	time_t t;
	time(&t);
	char *timeStr = ctime(&t);
	timeStr[strlen(timeStr) - 1] = '\0';
	return timeStr;
}

char *__LevelString(LogLevel level)
{
	switch (level)
	{
	case INFO:
		return "INFO";
		break;
	case WARNING:
		return "WARNING";
		break;
	case ERROR:
		return "ERROR";
		break;
	case DEBUG:
		return "DEBUG";
		break;
	default:
		return "UNKNOWN";
		break;
	}
}

void Log(Logger *logger, LogLevel level, const char *callingFunction, const char *fmt, ...)
{
	if (logger->level <= level - 1)
		return;

	char *timeStr = __TimeString();
	char *levelString = __LevelString(level);
	char *formatString = calloc(1, strlen(timeStr) + strlen(fmt) + strlen(levelString) + strlen(callingFunction) + 7);

	strcat(formatString, timeStr);
	strcat(formatString, " ");
	strcat(formatString, levelString);
	strcat(formatString, " ");
	strcat(formatString, callingFunction);
	strcat(formatString, " - ");
	strcat(formatString, fmt);
	strcat(formatString, "\n");

	va_list args;
	va_start(args, fmt);

	vfprintf(logger->file, formatString, args);

	if (level == ERROR && logger->printErrToStderr != 0)
		vfprintf(stderr, formatString, args);

	free(formatString);

	va_end(args);
}
