/*
 *	========================================================
 *
 *	libdisk
 * 	Date Added: 11/04/2023
 * 	Copyright Altel Corporation, all rights reserved.
 * 	
 * 	========================================================
 */

#ifndef _LIBDISK_DISK_H
#define _LIBDISK_DISK_H

#include <private/inc.h>

typedef long int dpos_t;

typedef struct _sDISK
{
    FILE* fs_fp;
    dpos_t fs_pos;
    uint8_t fs_lock;
    uint32_t fs_type;
} DISK;

enum 
{
    FS_RAMFS,
    FS_EXT4,
    FS_NSFS,
    FS_FAT32,
} LIBDISK_FS_TYPE;

#define LIBDISK_FS_TYPE_COUNT (4U)

DISK* dopen(const char* path, const char* res);
void dclose(DISK* dh);

size_t dwrite(DISK* dh, const char* bytes, size_t sz);
size_t dread(DISK* dh, char* bytes, size_t sz);
int dseek(DISK* dh, dpos_t* pos);

typedef DISK *DISKPTR;
typedef FILE *FILEPTR;

#endif /* ifndef _LIBDISK_DISK_H */
