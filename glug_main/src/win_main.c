#include <windows.h>
#include <glug/main.h>

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show_flag)
{
  (void)inst;
  (void)prev;
  (void)cmd;
  (void)show_flag;

  return glug_main(__argc, __argv);
}
