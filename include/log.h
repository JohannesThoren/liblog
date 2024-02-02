/**
 * @file log.h
 * @author Johannes Thorén <johannes@lgjt.xyz>
 * @brief 
 * @version 0.1
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#ifndef LOG_H
#define LOG_H

/**
 * @brief 
 * 
 */
typedef enum LogLevel
{
  INFO,
  WARNING,
  ERROR,
  DEBUG,
} LogLevel;

/**
 * @brief 
 * 
 */
typedef struct Logger
{
  LogLevel level;
  FILE *file;
  int printErrToStderr;
} Logger;

// the global logger, defined in log.c
// this only exists so we do not need to pass in
// the logger as an argument to every function.
extern Logger logger;

/**
 * @brief 
 * 
 * @param level 
 * @param file 
 */
void InitLogger(LogLevel level, FILE *file);

/**
 * @brief 
 * 
 * @param boolean 
 */
void PrintErrToStderr(int boolean);

/**
 * @brief prints a log message to a spcified file
 * 
 * @param logger 
 * @param level 
 * @param callingFunction 
 * @param fmt 
 * @param ... 
 */
void Log(Logger *logger, LogLevel level, const char *callingFunction, const char *fmt, ...);

#define LOG_INFO(fmt, ...) \
  Log(&logger, INFO, __func__, fmt, __VA_ARGS__)

#define LOG_WARNING(fmt, ...) \
  Log(&logger, WARNING, __func__, fmt, __VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
  Log(&logger, ERROR, __func__, fmt, __VA_ARGS__)

#define LOG_DEBUG(fmt, ...) \
  Log(&logger, DEBUG, __func__, fmt, __VA_ARGS__)

#endif
