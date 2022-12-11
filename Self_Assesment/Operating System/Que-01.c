//  C program to implement I/O system call
#include <stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main(){
    int c = 99,fd,sz;
    char *c1=(char*)calloc(100,sizeof(char));

    while(c != 0)
    {
        printf("1.Create\n 2.Open\n 3.Close\n 4.Write\n 5.Read\n 6.exit\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1:
                fd = creat("file1.txt",0777);
                // creat = create pointer to the file and store it in fd
                printf("fd = %d\n",fd);
                close(fd);
                break;
            case 2:
                fd=open("file1.txt",O_RDONLY|O_CREAT,0777);
                printf("fd=%d\n",fd);
                close(fd);
                break;
            case 3:
                close(fd);
                printf("fd=%d\n",fd);
                break;
            case 4:
                fd = open("file1.txt",O_WRONLY | O_CREAT ,0777);
                sz = write(fd,"hi,I am vaishnavi narkhede\n",strlen("hi,I am vaishnavi narkhede\n"));
            case 5:
                fd = open("file1.txt",O_RDONLY);
                sz = read(fd,c1,100);
                printf("sz = %d\n",sz);
                printf("fd = %d\n",fd);
                c1[sz] = '\0';
                printf("%s\n",c1);
                close(fd);
                break;
            case 6:
                printf("Thanks for using my code");
                exit(0);
        }
    }
}