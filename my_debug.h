/******************************************************************************
 * Prototype for debug info handler
 * (C) G. Liptak 2004-2005
 ******************************************************************************/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdio.h>

#ifndef _BEGIN_STD_C
#ifdef __cplusplus
#define _BEGIN_STD_C extern "C" {
#define _END_STD_C   }
#else
#define _BEGIN_STD_C
#define _END_STD_C
#endif /* __cplusplus */
#endif /* _BEGIN_STD_C */

_BEGIN_STD_C

extern int debug_level_param;
extern FILE *debug_out;

int dprintf(int debug_level, const char *pszFormat, ...);
void debug_init(const char *debug_file_name, FILE *d_out);
void debug_end(void);
const char *dbg_spintf(const char *pszFormat, ...);
void dflush(void);

_END_STD_C

#endif /* _DEBUG_H_ */
