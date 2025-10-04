#!/bin/bash

MOUNT_POINT="/mnt/kyria"

# First, check if already mounted and unmount if so
if mountpoint -q "$MOUNT_POINT"; then
    logger "Kyria mount point still mounted, unmounting first"
    umount "$MOUNT_POINT"
fi

# Wait a moment for the device to settle
sleep 1

# The device is passed as parameter (e.g., "sda1")
if [ -n "$1" ]; then
    DEVICE="/dev/$1"
else
    # Fallback: try to find by label
    DEVICE="/dev/disk/by-label/RPI-RP2"
fi

# Create mount point if it doesn't exist
mkdir -p "$MOUNT_POINT"

# Get the user who should own the mount (first logged in user)
MOUNT_USER=$(who | awk '{print $1}' | head -n1)
MOUNT_UID=$(id -u "$MOUNT_USER" 2>/dev/null)
MOUNT_GID=$(id -g "$MOUNT_USER" 2>/dev/null)

# Mount the device with vfat filesystem and proper permissions
if [ -n "$MOUNT_UID" ] && [ -n "$MOUNT_GID" ]; then
    mount -t vfat -o uid=$MOUNT_UID,gid=$MOUNT_GID,umask=0022 "$DEVICE" "$MOUNT_POINT"
else
    # Fallback: mount with permissive umask
    mount -t vfat -o umask=0000 "$DEVICE" "$MOUNT_POINT"
fi

# Log the result
if [ $? -eq 0 ]; then
    logger "Kyria keyboard mounted at $MOUNT_POINT from $DEVICE"
else
    logger "Failed to mount Kyria keyboard from $DEVICE"
fi

exit 0
