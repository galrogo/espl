#include <assert.h>
#include "bclib.h"

/* TODO: implement bc_char2bits */

int bc_bits2char(int *bits) {
	int ch = 0;
	int i;

	for(i = BC_NBITS;  i!=0;) { --i;
		ch = (ch<<1) | bits[i];
	}

	return ch;
}

int *bc_char2bits(int ch, int *bits)
{
  int i;
  for (i=0;i<8;i++)
    {
      bits[i]=ch%2;
      ch=ch/2;
    }
  return bits;
}

#ifndef TESTBC
#define TESTBC 0
#endif

#if TESTBC
/** Testing */

/* converts ch to itself via bits, for testing */
static int char2char(int ch) {
	int bits[BC_NBITS];

	return bc_bits2char(bc_char2bits(ch, bits));
}

void bc_test() {
	int bits[BC_NBITS] = {0, 0, 0, 0, 0, 1, 0, 0};
	int i;
	
	assert(bc_bits2char(bits)==' ');
	assert(char2char(0)==0);
	assert(char2char(' ')==' ');
	for (i=0; i<8; i++)
	{
	  printf("%d ", bits[i]);
	}
}

int main() {
	bc_test();
	return 0;
}
#endif
