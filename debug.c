#include <stdio.h>
#include <stdarg.h>
#include "my_debug.h"

FILE *debug_out = NULL;
static int debug_file = 0;

int dprintf(int debug_level, const char *pszFormat, ...)
{
  if (debug_out == NULL)
    debug_init(NULL, NULL);
  if ((debug_level <= debug_level_param) && (debug_out != NULL))
  {
  va_list argptr;
    if (!debug_out)
      debug_out = stdout;
    va_start(argptr, pszFormat);
    vfprintf(debug_out,pszFormat,argptr);
    va_end(argptr);
  }
  return 0;
}

void debug_init(const char *debug_file_name, FILE *d_out)
{
  debug_end();
  if (d_out != NULL)
  {
    debug_out = d_out;
  }
  if (debug_file_name)
  {
    debug_out = fopen(debug_file_name,"at");
    if (debug_out)
      debug_file = 1;
    else
      fprintf(stderr,"Could not open %s file for appending!\n",debug_file_name);
  }
  if (!debug_out)
  {
    if (d_out != NULL)
      debug_out = d_out;
#ifndef DEBUG_STDOUT_DISABLE
    else
      debug_out = stdout;
#endif
  }
}

void debug_end(void)
{
  if (debug_file)
  {
    fclose(debug_out);
    debug_file = 0;
    debug_out = stdout;
  }
}
