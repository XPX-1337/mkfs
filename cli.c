/*
 *	========================================================
 *
 *	mkfs
 * 	Date Added: 10/04/2023
 * 	Last Edited: 12/04/2023
 *
 * 	Copyright Altel Corporation, all rights reserved.
 *
 * 	========================================================
 */

#include <string.h>
#include <stdio.h>
#include "include/cli.h"

static void do_mkfs_version(void)
{
    printf("%s \n", "mkfs.nsfs: a disk image tool for CTSS.");
    printf("%s \n", "Copyright Altel Corporation, all rights reserved");
}

int mkfs_cli(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-v") == 0)
        {
            do_mkfs_version();
            return 0;
        }
    }

    return 0;
}