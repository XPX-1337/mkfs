/*
 *	========================================================
 *
 *	libdisk
 * 	Date Added: 13/04/2023
 * 	Copyright Amlal El Mahrouss, all rights reserved.
 *
 * 	========================================================
 */

#include <nsfs-xpm.h>

ssize_t nsfs_do_write_xpm(nsfs_xpm_t* part, DISK* disk)
{
    if (part == NULL) return -1;
    if (disk == NULL) return -1;

    return dwrite(disk, (const char*)part, sizeof(nsfs_xpm_t));
}