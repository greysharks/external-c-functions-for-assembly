#include <stdio.h>
#include <stdlib.h>

extern unsigned int* lossless_multiplication(unsigned int, unsigned int);

unsigned int* lossless_multiplication(unsigned int mem1, unsigned int mem2) {
	unsigned int a, b, c, d;

	// upper_half
	a = mem1;
	a = a >> 0x10;
	c = mem2;
	c = c >> 0x10;
	a = a * c;
	b = a;
	a = mem1;
	a = a >> 0x10;
	c = mem2;
	c = c & 0xFFFF;
	a = a * c;
	d = b;
	d = d >> 0x10;
	a = a + d;
	b = b << 0x10;

	// lower_half
	d = mem1;
	d = d & 0xFFFF;
	c = mem2;
	c = c >> 0x10;
	d = d * c;
	b = b + d;
	d = mem1;
	d = d & 0xFFFF;
	c = mem2;
	c = c & 0xFFFF;
	d = d * c;
	c = d;
	c = c >> 0x10;
	a = a + c;
	d = d & 0xFFFF;

	// add_with_carry
	c = b;
	b = b & 0xFFFF;
	c = c >> 0x10;
	c = c + d;
	d = c;
	d = d & 0xFFFF;
	c = c >> 0x10;
	a = a + c;

	// _end
	c = a;
	a = b;
	d = c;
	c = 0;
	b = 0;

	printf(" %016X\n*\n %016X\n=\n %08X%08X\n", mem1, mem2, d, a);

	unsigned int* p = (unsigned int*) malloc(sizeof(unsigned int) * 2);

	p[0] = a;
	p[1] = d;

	return p;
}
