qemu-system-x86_64 -L . --bios $(pwd)/edk2/Build/OvmfX64/DEBUG_GCC5/FV/OVMF.fd -hda fat:rw:hda-contents -net none
