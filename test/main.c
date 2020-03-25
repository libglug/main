#include <glug/main.h>

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*
 * ASSERTs that argc is 2 strings ["HELLO", "glug"]
 */

int glug_main(int argc, char *argv[])
{
    printf("assert argc == 3 ([0] binary name, [1,2] arguments)\n");
    assert(argc == 3);

    printf("assert argv[1] == HELLO\n");
    assert(!strcmp(argv[1],  "HELLO"));

    printf("assert argv[2] == glug\n");
    assert(!strcmp(argv[2],  "glug"));

    return 0;
}
