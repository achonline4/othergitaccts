#include <stdio.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr, "Invalid arguments!\n");
		exit(EXIT_FAILURE);
	}

	return get_hw_addr(argv[1]);
}

int get_hw_addr(const char* iface)
{
	int retval;
	struct ifreq dev;
	int sockfd;
	unsigned char mac[14];


	if(strlen(iface)>IFNAMSIZ)
	{
		fprintf(stderr, "Interface name exceeds maximum limit!\n");
		return -1;
	}

	strcpy(dev.ifr_name, iface);
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sockfd<0)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	fprintf(stdout, "ioctl = %d\n", ioctl(sockfd, SIOCGIFHWADDR, &dev));
	int i;
	for(i=0;i<6;++i){
		fprintf(stdout, "%u\n", dev.ifr_addr.sa_data[i]&0x000000ff);
		//if(i<5)
		//	fprintf(stdout, ":");
	}
	fprintf(stdout, "\n\n");
	for(i=0;i<6;++i){
		fprintf(stdout, "%x\n", dev.ifr_addr.sa_data[i]&0x000000ff);
		//if(i<5)
		//	fprintf(stdout, ":");
	}
	fprintf(stdout, "\n, size = %d\n", IFNAMSIZ);

	return 0;
}
