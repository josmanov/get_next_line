#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define buffer = 1024

char	*get_next_line(int fd)
{
	int bytes

	if (fd == NULL)
		return = NULL;

}

int main(){
    
    char* fileName = "hello.txt";

    int fd = ;
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }

    char buffer[50];

    int bytesRead = read(fd, buffer, 15);

    printf("%d bytes read!\n", bytesRead);
    printf("File Contents:\n%s\n", buffer);

    return 0;
}
