#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, bit, res = 0;                   // 0...0010010
	                                          // 0...0011001
	                                          //     XOR
	                                          // 0...0001011
	                                          // 0.000000001 - проходимся единичкой с помошью &
	scanf("%d%d", &a, &b);

	bit = a ^ b;                      
	for (int i = 0; i < 32; i++) 
	{
		if ( (bit & (1 << i)) != 0)
		{
			res++;
		}
	}
	printf("%d", res);
}