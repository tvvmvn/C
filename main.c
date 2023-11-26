#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/*
Error handling
Suppose there is an error deep down in a function nested in many other functions and error handling makes sense only in the top level function.

It would be very tedious and awkward if all the functions in between had to return normally and evaluate return values or a global error variable to determine that further processing doesn't make sense or even would be bad.

That's a situation where setjmp/longjmp makes sense. Those situations are similar to situation where exception in other langages (C++, Java) make sense.

Coroutines
Besides error handling, I can think also of another situation where you need setjmp/longjmp in C:

It is the case when you need to implement coroutines.

Here is a little demo example. I hope it satisfies the request from Sivaprasad Palas for some example code and answers the question of TheBlastOne how setjmp/longjmp supports the implementation of corroutines (as much as I see it doesn't base on any non-standard or new behaviour).

EDIT:
It could be that it actually is undefined behaviour to do a longjmp down the callstack (see comment of MikeMB; though I have not yet had opportunity to verify that).
*/


#include <stdio.h>
#include <setjmp.h>

jmp_buf bufferA, bufferB;

void routineB(); // forward declaration 

void routineA()
{
    int r ;

    printf("- 12 : (A1)\n");

    r = setjmp(bufferA);
    if (r == 0) routineB();

    printf("- 17 : (A2) r=%d\n",r);

    r = setjmp(bufferA);
    if (r == 0) longjmp(bufferB, 20001);

    printf("- 22 : (A3) r=%d\n",r);

    r = setjmp(bufferA);
    if (r == 0) longjmp(bufferB, 20002);

    printf("- 27 : (A4) r=%d\n",r);
}

void routineB()
{
    int r;

    printf("- 34 : (B1)\n");

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10001);

    printf("- 39 : (B2) r=%d\n", r);

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10002);

    printf("- 44 : (B3) r=%d\n", r);

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10003);
}


int main(int argc, char **argv) 
{
    routineA();
    return 0;
}
