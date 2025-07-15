#include<netinet/in.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	uint32_t hap =0;
	uint32_t num2=0;
	FILE *fp= NULL;
	for(int i=1; i<=3;i++){
		if((fp = fopen(argv[i], "rb"))==NULL){
			printf("error");
			exit(1);
		}
		fread(&num2 , sizeof(num2), 1, fp);
		num2 = ntohl(num2);
		printf("%d(0x%08x)", num2,num2);
		hap += num2;
		if(i+1!=4)
			printf(" + ");
		else{
		
			printf("= %d(0x%08x)", hap, hap);		
		}
		fclose(fp);
	}
}


