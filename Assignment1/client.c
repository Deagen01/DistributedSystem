#include <stdio.h>
#include <rpc/rpc.h>
#include "date.h"

main(argc,argv)
int argc;
char **argv;
{
    CLIENT *cl;
    char *server;
    long *lresult;
    char **sresult;
    if(argc !=2){

        fprintf(stderr,"usage: %s hostname\n", argv[0]);
        exit(1);
    }
    server=argv[1];
    if((cl=clnt_create(server,DATE_PROG,DATE_VERS,"UDP"))==NULL){
        clnt_pcreateerror(server);
        printf("clnt_create");
        exit(1);
    }
    if((lresult=bin_date_1(NULL,cl))==NULL){
        clnt_perror(cl,server);
        exit(1);
    }
    printf("time on %s is %ld\n",server,*lresult);
    if ((sresult=str_date_1(lresult,cl))==NULL){
        clnt_perror(cl,server);
        exit(1);
    }
    printf("date is %s\n", *sresult);
    clnt_destroy(cl);
    exit(0);
}