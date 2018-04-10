#include <sys/types.h>
#include <sys/socket.h>

int main()
{
    char msg[100];
    int sd,client,portNumber;
    socklen_t len;
    int n=0;
    struct sockaddr_in servAdd;

    if(argc != 2)
    {
        fprintf(stderr,"Callnot proper.\n");
        exit(0);
    }

    if((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        fprintf(stderr,"Could not create socket.\n");
        exit(1);
    }
    
    servAdd.sin_family = AF_INET;
    servAdd.sin_addr.s_addr = htonl(INADDR_ANY);
    sscanf(argv[1], "%d", &portNumber);
    servAdd.sin_port = htons((unint16_t)portNumber);

    bind(sd, (struct sockaddr *) &servAdd, sizeof(servAdd));
    listen(sd, 5)
    
    client = accept(sd, (struct sockaddr*)NULL,NULL);

    while(1)
    {
        if(n = read(sd,msg,100))
        {
            msg[n]= '\0';
            fprintf(stderr,"Client: %s\n",msg);
            msg = "Acknowledged: "+msg;            
            fprintf(stderr,"Sending same message to client...");
            write(sd,msg,strlen(msg)+1)
            if(!strcmp(msg, "Bye\n"))
            {
                kill(pid.SIGTERM);
                exit(0);
            }
        }
    }
retrun 0;
}
