#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>
#include <netinet/in.h>

static void iface_up(const char* iface)
{
	struct ifreq ifr;
	int sock = socket(PF_INET6, SOCK_DGRAM, IPPROTO_IP);
	memset(&ifr, 0, sizeof(ifr));
	strcpy(ifr.ifr_name, iface);
	if (ioctl(sock, SIOCGIFFLAGS, &ifr) < 0) {
		perror("SIOCGIFFLAGS");
	}
	close(sock);
	printf("up = %d\n", ifr.ifr_flags & IFF_UP);
}

int main(int argc, char** argv)	
{
	const char* iface = argv[1];
	iface_up(iface);
}
