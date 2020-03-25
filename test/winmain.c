#include <glug/main.h>

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

/*
 * ASSERTs that argv is 4 strings ["HELLO", "hallo", "hola", "こんにちは"]
 */

int glug_main(int argc, char *argv[])
{
    printf("assert argc == 5 ([0] binary name, 4 arguments)\n");
    assert(argc == 5);

    printf("assert argv[1] == HELLO\n");
    assert(!wcscmp((wchar_t *)argv[1],  L"HELLO"));

    printf("assert argv[2] == hallo\n");
    assert(!wcscmp((wchar_t *)argv[2],  L"hallo"));

    printf("assert argv[3] == hola\n");
    assert(!wcscmp((wchar_t *)argv[3],  L"hola"));

    printf("assert argv[4] == こんにちは(konnichiwa)\n");
    assert(!wcscmp((wchar_t *)argv[4],  L"こんにちは"));

    return 0;
}
