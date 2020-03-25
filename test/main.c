#include <glug/main.h>

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * ASSERTs that argv is 4 strings ["HELLO", "hallo", "hola", "こんにちは"]
 */

int glug_main(int argc, char *argv[])
{
    printf("assert argc == 5 ([0] binary name, 4 arguments)\n");
    assert(argc == 5);

    printf("assert argv[1] == HELLO\n");
    assert(!strcmp(argv[1],  "HELLO"));

    printf("assert argv[2] == hallo\n");
    assert(!strcmp(argv[2],  "hallo"));

    printf("assert argv[3] == hola\n");
    assert(!strcmp(argv[3],  "hola"));

    printf("assert argv[4] == こんにちは(konnichiwa)\n");
    assert(!strcmp(argv[4],  "こんにちは"));

    return 0;
}
