#include <stdio.h>
#include <stdlib.h>

/*
	This function(add_one) add bit string x and bit string y
	that consist of only 1 and 0.
	
	The length of these bit string is word_size.
	Typically, it's the mahcine word size, say 8, 16,
	32 or 64. If you specify the param word_size is 8, it
	is YOUR responsibility to ensure the length of x and y
	correctly.

	The tested word size is 8, but it should work when
	word_size is other values. res_one stores the
	computing result.

	'carry' store the carry of add_one function.

	For multiple word, you just need to specify the word_size to
	different value, for example, the 3 words adds, specify
	word_size to 24(when word size is 8), and input x and y string.
 		
	add_one testing results:
	~/.../ch1(master)$ ./a.out 
	input two bit string, separated by new line:
	00010110
	00010010
	the add of these two bit string: 00101000
	the carry bit is: 0
	~/.../ch1(master)$ ./a.out 
	input two bit string, separated by new line:
	11111111
	11111111
	the add of these two bit string: 11111110
	the carry bit is: 1
*/

int add_one(char *x, char *y, int word_size, char *res_one, int *carry)
{
	*carry = 0;
	int i, tmp;

	for (i = word_size - 1; i >= 0; i--)
		{
			tmp = (int)(x[i] - 48) + (int)(y[i] - 48) + *carry;
			
			if (tmp == 0 || tmp == 1)
				{
					*carry = 0;
					res_one[i] = (char)(tmp + 48);
				}
			else
				{
					*carry = 1;
					res_one[i] = (char)((tmp - 2) + 48);
				}
		}
	return 0;
}

int main(int argc, char *argv[])
{
	char *x = malloc(sizeof(char) * 8);
	char *y = malloc(sizeof(char) * 8);
	char *res_one = malloc(sizeof(char) * 8);
	int *carry1 = malloc(sizeof(int));
	printf("input two bit string, separated by new line:\n");
	scanf("%s", x);
	scanf("%s", y);
	add_one(x, y, 8, res_one, carry1);
	printf("the add of these two bit string: %s\n", res_one);
	printf("the carry bit is: %d\n", *carry1);
	
	return 0;
}

