#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	for(i = 0; i < 4; i++)
        four_c[i] = 'A' + i; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
	printf("four_ints\n");
	printf("%x\n", four_ints[0]);
	printf("%x\n", four_ints[1]);
	printf("%x\n", four_ints[2]);
	printf("%x\n", four_ints[3]);
	printf("four_ints address\n");
	for(i = 0; i < 4;i++){
		printf("%p\n", &four_ints[i]);
	}

	printf("four_c\n");
	printf("%x\n", four_c[0]);
	printf("%x\n", four_c[1]);
	printf("%x\n", four_c[2]);
	printf("%x\n", four_c[3]);
	printf("four_c address\n");
	for(i = 0; i < 4;i++){
		printf("%p\n", &four_c[i]);
	}
	
	return 0;
}