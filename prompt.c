#include <stdio.h>                                                                
#include<stdlib.h>
int main(void){         
       	char  *buffer = NULL;                                                                         

//        ssize_t num_read;                                                         
	printf("----\n");
        size_t n = 0;
	getline(&buffer,&n,stdin);                                          
	printf("$ ");
	printf("%s\n",buffer);
//	printf("%ld",num_read);
	return 0;
}
