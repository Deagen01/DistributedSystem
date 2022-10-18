#include <stdio.h>

long bin_date(void);
char *str_date(long bintime);

main(int argc, char **argv){
    long lresult;
    char *sresult;
    if (argc !=1){
        fprintf(stderr,"usage: %s \n", argv[0]);
        exit(1);
    }
    /*调用程序bin_date*/
    lresult = bin_date();
    printf("time is %ls\n",lresult);
    /*将结果转换为date string*/
    sresult = str_date(lresult);
    printf("date is %s",sresult);
    exit(0);


}

long bin_date(void){
    long timeval;
    long time();

    timeval = time((long *)0);
    return timeval;
}

char *str_date(long bintime){
    char *ptr;
    char *ctime();

    ptr = ctime(&bintime);
    return ptr;
}