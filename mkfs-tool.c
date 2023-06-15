/*
 *	========================================================
 *
 *	mkfs
 *
 * 	Date Added: 10/04/2023
 * 	Last Edited: 15/05/2023
 *
 * 	Copyright Altel Corporation, all rights reserved.
 *
 * 	========================================================
 */

#include <disk.h> /* libdisk */
#include <nsfs-xpm.h>

/* libc */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* libc */

/* uuid */
#include <uuid/uuid.h>

#include <mkfs-tool.h> /* mkfs cli logic */

static void do_mkfs_version(void)
{
    printf("%s \n", "mkfs.nsfs: a disk image tool for CTSS.");
    printf("%s \n", "Copyright Altel Corporation, all rights reserved");
}

int mkfs_cli(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], "--version") == 0 || 
            strcmp(argv[i], "-v") == 0)
        {
            do_mkfs_version();
            return 0;
        }

        if ((strcmp(argv[i], "--xpm") == 0) ||
            (strcmp(argv[i], "--tss-partition") == 0))
        {
            do_mkfs_version();
            printf("%s", "Creating partition for TSS...\n");

            const char* filename = argv[i+1];
            
            if (filename == NULL)
            {
              printf("%s", "Mkfs.NSFS : Please provide a partition file!\n");
              return 0;
            }

            DISK* disk = dopen(filename, "wb");
            nsfs_xpm_t part;
      
            part.h_flags |= 8; // SCSI, AT, SATA compatible
                              // xpm must comply to all three.
            
            part.h_version = 1;
            part.h_size = sizeof(nsfs_xpm_t);

            part.h_low = 0;
            part.h_high = 16;

            part.h_type |= XPM_PARTITION_SYSTEM | XPM_PARTITION_BOOT;
           
            uuid_t out = { 0 };

            /* don't use time nor uuid_generate, we seek randomness to prevent production issues. */
            uuid_generate_random(out);
            
            memcpy(part.h_uuid, out, 16);

            if (nsfs_do_write_xpm(&part, disk) == 0)
            {
                perror("mkfs.nsfs (operation failed) -> ");
            }
        }
    }

    return 0;
}
