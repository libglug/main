#ifndef GLUG_EXTERN_MAIN_H
#define GLUG_EXTERN_MAIN_H
#ifndef GLUG_EXTERN_START
  #ifdef __cplusplus

    #define GLUG_EXTERN_START extern "C" {

  #else

    #define GLUG_EXTERN_START

  #endif
#endif

#ifndef GLUG_EXTERN_END
  #ifdef __cplusplus

    #define GLUG_EXTERN_END }

  #else

    #define GLUG_EXTERN_END

  #endif
#endif

GLUG_EXTERN_START

int glug_main(int argc, char **argv);

GLUG_EXTERN_END

#endif // GLUG_EXTERN_MAIN_H
