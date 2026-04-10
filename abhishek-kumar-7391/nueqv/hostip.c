/* an implementation of nslookup */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <errno.h>

char* host;
struct addrinfo hints;
struct addrinfo* res; /* store the result */

static void 
set_hints(void) {
	hints.ai_family   = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags    = hints.ai_flags | AI_CANONNAME;
}

static int 
print_host_info(void){
	char* host_ip;
	struct sockaddr_in* ip;
	if(!res)
		return -1;
	host_ip = malloc(INET_ADDRSTRLEN);
	if(!host_ip)
		return -1;
	fprintf(stdout, "Ipv4 address/es:\n");
	while(res){
		if(res->ai_canonname)
			fprintf(stdout, "Canonical name = %s\n",
					(char*)res->ai_canonname);
		ip = (struct sockaddr_in*)res->ai_addr;
		if(inet_ntop(AF_INET, (struct sockaddr_in*)&(ip->sin_addr),
		host_ip,INET_ADDRSTRLEN) == '\0'){
			perror("ntop");
			exit(EXIT_FAILURE);
		}else
			fprintf(stdout, "\t%s\n", host_ip);
		memset(host_ip, '\0', INET_ADDRSTRLEN);
		res = res->ai_next;
	}
	if(host_ip)
		free(host_ip);
}

static int 
lookup_host(void){
	int retval;

	retval = 0;
	/* initiaise the adrinfo hints */
	set_hints();
	switch(getaddrinfo(host, NULL, &hints, &res)) {
		case 0:
			break;
		default:
			fprintf(stderr, "%s\n", gai_strerror(errno));
			retval = -1;
	}
done:	
	return retval;
}

static int 
parse_cmdline(char* hostname) {
	if(!hostname)
		return -1;
	else 
		host = strdup(hostname);
	if(!host)
		return -1;
	#ifdef DEBUG
	printf("host = %s\n", host);
	#endif

}

int main(int argc, char* argv[]){
	if(argc==1){
		fprintf(stderr, "No host to lookup!\n");
		exit(EXIT_FAILURE);
	}
	if(parse_cmdline(argv[1])<0)
		goto err;
	lookup_host();
	printf("Hostname = %s\n", host);
	print_host_info();
err:
	if(host)
		free(host);
	return -1;
}

/* algorithm 
	-> initialise the hints
	-> use getaddrinfo to get host info in  struct addrinfo
	-> dump the res structure 
*/
