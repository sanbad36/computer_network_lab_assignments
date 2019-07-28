//Name-sanket 

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
//The header files are the same as for the server with one addition. The file netdb.h defines the structure hostent, which will be used below.
void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;
//he variable server is a pointer to a structure of type hostent. This structure is defined in the header file netdb.h as follows:


//struct  hostent {
      //  char    *h_name;        /* official name of host */
      //  char    **h_aliases;    /* alias list */
       // int     h_addrtype;     /* host address type */
       // int     h_length;       /* length of address */
      //  char    **h_addr_list;  /* list of addresses from name server */
//#define h_addr  h_addr_list[0]  /* address, for backward compatiblity */
};


/*

It defines a host computer on the Internet. The members of this structure are:
h_name       Official name of the host.

h_aliases    A zero  terminated  array  of  alternate
             names for the host.

h_addrtype   The  type  of  address  being  returned;
             currently always AF_INET.

h_length     The length, in bytes, of the address.

h_addr_list  A pointer to a list of network addresses
             for the named host.  Host addresses are
             returned in network byte order.
  */ 
  
  
  
   char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
        
        
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    return 0;
}
