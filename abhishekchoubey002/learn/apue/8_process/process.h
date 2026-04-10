#ifndef PROCESS_INFO
#define PROCESS_INFO
#include <unistd.h>

struct process_info {
	int pid;
	int uid;
	int gid;
	int ppid;
};
#endif
