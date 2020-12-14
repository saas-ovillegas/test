#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"
#include <stdio.h>

//--------------------------------------------------------------------
// Global Variables

#endif // _GLOBALS_H

void write_to_file(const char *filepath, const char *data)
{
    FILE *fp = fopen(filepath, "a");
    if (fp != NULL)
    {
        fputs(data, fp);
        fclose(fp);
    }
}