#include <glug/main.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show_flag)
{
    int res, argc;
    LPWSTR *argv, cmd_line;

    (void)inst;
    (void)prev;
    (void)cmd;
    (void)show_flag;

    cmd_line = GetCommandLineW();
    argv = CommandLineToArgvW(cmd_line, &argc);
    res = glug_main(argc, (char **)argv); // pass argv as a char *[]
    LocalFree(argv);

    return res;
}
