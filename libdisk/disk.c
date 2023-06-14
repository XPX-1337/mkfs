/*
 *	========================================================
 *
 *	libdisk
 * 	Date Added: 10/04/2023
 * 	Copyright Altel Corporation, all rights reserved.
 * 	
 * 	========================================================
 */

#include <disk.h>

DISK* dopen(const char* path, const char* res)
{
    DISK* dh = malloc(sizeof(DISK));
    if (dh == NULL) return NULL;
    
    dh->fs_fp = fopen(path, res);
    return dh;
}

void dclose(DISK* dh)
{
    if (dh != NULL)
    {
        fclose(dh->fs_fp);
        free(dh);
    }
}

size_t dwrite(DISK* dh, const char* bytes, size_t sz)
{
    if (dh == NULL) return (size_t)~0;
    if (dh->fs_lock) return (size_t)~0;

    dh->fs_lock = 1;
    size_t ret = fwrite(bytes, sz, SEEK_CUR, dh->fs_fp);
    dh->fs_lock = 0;

    return ret;
}

size_t dread(DISK* dh, char* bytes, size_t sz)
{
    if (dh == NULL) return (size_t)~0;
    if (dh->fs_lock) return (size_t)~0;

    dh->fs_lock = 1;
    size_t ret = fread(bytes, sz, SEEK_CUR, dh->fs_fp);
    dh->fs_lock = 0;

    return ret;
}

int dseek(DISK* dh, dpos_t* pos)
{
    if (dh != NULL && pos != NULL)
    {
        dh->fs_pos = *pos;
        return *pos = fseek(dh->fs_fp, *pos, SEEK_SET);
    }

    return -1;
}