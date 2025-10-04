# Scripts for automatically mounting keyboard when it enters bootloader mode
> [!info]
> Tested on kyria rev3 with liatris controller, millage *may* vary

# How to use
1. Copy `kyria-automount.sh` and `kyria-unmount.sh` to `/usr/local/bin`
2. Copy `99-kyria.rules` to `/etc/udev/rules.d/`
3. Copy `kyria-automount@.service` and `kyria-unmount@.service` to `/etc/systemd/system/`
4. Run `sudo udevadm control --reload-rules` for `99-kyria.rules` to take effect
5. Run `sudo systemctl daemon-reload` for systemctl services to take effect

> [!warning]
> unmount script and udev-rule is flaky, automount automatically runs unmount in case unmount script does not work
