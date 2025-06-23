// Big Header

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#include "frames.h"

#define CLEAR		"\033[H\033[J" 
#define CMD_WIDTH	50
#define CMD_HEIGHT	18

#define CHAR_WIDTH		13
#define CHAR_HEIGHT		31

# ifndef DEBUG
#  define DEBUG 0
# endif // !DEBUG

# if DEBUG == 1
#  define PRINT_DEBUG(message, ...)	fprintf(stderr, "DEBUG: %s:%d:%s(): " message "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#  define PRINT_ERROR(message, ...)	fprintf(stderr, "ERROR: %s:%d:%s(): " message ": %s\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__, strerror(errno))
# else
#  define PRINT_DEBUG(message, ...)
#  define PRINT_ERROR(message, ...)
# endif // !DEBUG

enum e_action
{
	e_raid,
	e_invasion,
	e_takeover,
	e_cleaning,
	e_quit
};

#endif // !CONFIG_H