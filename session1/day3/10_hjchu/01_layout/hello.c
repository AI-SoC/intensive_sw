#include <stdio.h>

//#define ALIGNED 1

#ifdef ALIGNED
struct foo {
	int		a;
	short	b;
	short 	h;	
	int 	d;
	char	e;
	char	f;
	char	g;
	char	c;
};

#else

struct foo {
	int		a;
	short	b;
	short 	h;	
	int 	d;
	char	e;
	char	f;
	char	g;
	char	c;
};

#endif

int main(void)
{
	struct foo f1 = {
		0x12345678,
		0xFBCD,
		0XDDFF,
		0X12345678,
		0XAB,
		0XCC,
		0XEE,
		0XEE
	};

	printf("struct foo's size is %lu\n", sizeof(f1));

	return 0;
}
