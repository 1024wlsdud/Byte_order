#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


uint32_t read_bin(char** argv){
	FILE *fp;
	uint32_t t;
	
	// 파일 읽기
	if (( fp = fopen(argv[0], "rb")) == NULL){
		printf("Error ! \n");
		exit(1);
	}
	
	fread(&t, sizeof(uint32_t), 1, fp);
	printf("bin_data : 0x%08x\n", t);
	fclose(fp);
	return t;	
}

uint32_t Byte_order(uint32_t t){
	uint32_t num1, num2, num3, num4;
	// 결과값 저장
	uint32_t sum;

	num1 = (0xFF000000 & t) >> 24;
	num2 = (0x00FF0000 & t) >> 8;
	num3 = (0x0000FF00 & t) << 8;
	num4 = (0x000000FF & t) << 24;

	sum = num1 | num2 | num3 | num4;

	return sum;
}
int main(int argc, char** argv){
	
	uint32_t bin1;
	uint32_t bin2; 
	
	uint32_t sum;

	bin1 = read_bin(&argv[1]);	
	bin2 = read_bin(&argv[2]);

	// 바이트 오더링
	bin1 = Byte_order(bin1);
	bin2 = Byte_order(bin2);
	
	printf("bin1 : 0x%08x\n", bin1);
	printf("bin2 : 0x%08x\n", bin2);

	sum = bin1 + bin2;

	printf("sum: 0x%08x\n", sum);
	
}
