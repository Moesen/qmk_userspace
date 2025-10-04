#!/bin/bash

MOUNT_POINT="/mnt/kyria"

# Check if mounted
if mountpoint -q "$MOUNT_POINT"; then
    # Unmount the device
    umount "$MOUNT_POINT"
    
    if [ $? -eq 0 ]; then
        logger "Kyria keyboard unmounted"
        
        # Try to notify user if in graphical session (don't fail if it doesn't work)
        for user in $(who | awk '{print $1}' | sort -u); do
            user_id=$(id -u "$user" 2>/dev/null)
            if [ -n "$user_id" ]; then
                sudo -u "$user" DISPLAY=:0 DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/$user_id/bus notify-send "Kyria Keyboard" "Bootloader unmounted" 2>/dev/null || true
            fi
        done
    else
        logger "Failed to unmount Kyria keyboard"
    fi
fi

exit 0
