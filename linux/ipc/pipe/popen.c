#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void
print_result(FILE *fp)
{
        char buf[100];

        if(!fp) {
                return;
        }
        printf("\n>>>\n");
        while(memset(buf, 0, sizeof(buf)), fgets(buf, sizeof(buf) - 1, fp) != 0 ) {
                printf("%s", buf);
        }
        printf("\n<<<\n");
}

int
main(void)
{
        FILE *fp = NULL;

        char buf[10000];
        
        fp = NULL;
        fp = popen("ls 2>&1", "w");
        if(!fp) {
            perror("popen");
            exit(EXIT_FAILURE);
        }
		fputs(buf,fp);
		//while(fgets(buf,10000,fp)!=NULL)
		//	printf("%s",buf);
         pclose(fp);
         sleep(1);
        
}

