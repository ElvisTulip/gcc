/* Functional tests for the function hotpatching feature.  */

/* { dg-do compile } */
/* { dg-options "-O3 -mzarch -mhotpatch=0,1 -falign-functions=4096" } */

#include <stdio.h>

void __attribute__ ((aligned(2048))) hp1(void)
{
  printf("hello, world!\n");
}

/* Check number of occurences of certain instructions.  */
/* { dg-final { scan-assembler-times "\.align\t2048" 2 } } */
