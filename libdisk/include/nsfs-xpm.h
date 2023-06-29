/*
 *	========================================================
 *
 *	libdisk
 * 	Date Added: 13/04/2023
 * 	Copyright Xplicit Corporation, all rights reserved.
 *
 * 	========================================================
 */

#ifndef _LIBDISK_XPM_H
#define _LIBDISK_XPM_H

#include <private/inc.h>
#include <disk.h>

#define XPM_PART_MAGIC ("NSFS")
#define XPM_PART_LEN   (5U)

typedef uint64_t lba_t;

typedef struct __attribute__((aligned(4))) _nsfs_xpm
{
    char     h_signature[XPM_PART_LEN];
    uint32_t h_version;
    uint32_t h_size;
    uint16_t h_flags;
    uint16_t h_type;
    lba_t    h_low;
    lba_t    h_high;
    uint16_t h_uuid[16];
    char     h_checksum;
} nsfs_xpm_t;

typedef enum
{
    XPM_PARTITION_STANDARD = 1, /* standard partition */
    XPM_PARTITION_SYSTEM = 4, /* system partition */
    XPM_PARTITION_BOOT = 8, /* boot partition, used by RFI */
} XPM_PARTITION_TYPE;

typedef enum
{
    XPM_FLAGS_SCSI = 1, /* Disk is using scsi */
    XPM_FLAGS_SERIAL_AT = 2, /* Disk is using serial at */
    XPM_FLAGS_AT = 4, /* Disk is using AT */
} XPM_DISK_FLAGS;

#define XPM_PARTITION_TYPE_COUNT (3U)
#define XPM_DISK_FLAGS_COUNT (3U)

ssize_t nsfs_do_write_xpm(nsfs_xpm_t* part, DISK* disk);

#endif /* ifndef _LIBDISK_XPM_H */
