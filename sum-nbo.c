#include<netinet/in.h>
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>


uint32_t filereadvalue(char * Filename){
	FILE *fp;
	uint32_t num1 =0;
	for(int i=0; i<=3; i++){
		if((fp = fopen(Filename, "rb")) == NULL){
			printf("fopen error");
			exit(1);
		}
		fseek(fp, 0, SEEK_END);
		if( ftell(fp) < 4 ){
			printf(" ftell error");
			exit(1);
		}

		fseek(fp, 0, SEEK_SET);
		fread(&num1, sizeof(num1), 1, fp);
		fclose(fp);
		return ntohl(num1);
	}
}


int main(int argc, char *argv[]){
	uint32_t hap =0;
	uint32_t num2=0;
	for(int i=1; i<=3;i++){
		num2 = filereadvalue(argv[i]);
		printf("%d(0x%08x)", num2,num2);
		hap += num2;
		if(i+1!=4)
			printf(" + ");		
		}
	printf("= %d(0x%08x)", hap, hap);	
}



