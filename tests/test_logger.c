#include "log.h"

int main(int argc, char const *argv[])
{
	FILE *fptr = fopen("output.log", "a");
	InitLogger(DEBUG, fptr);
	PrintErrToStderr(1);
	LOG_INFO("%s", "this is a test message");
	LOG_WARNING("%s", "this is a test message");
	LOG_ERROR("%s", "this is a test message");
	LOG_DEBUG("%s", "this is a test message");

	return 0;
}
