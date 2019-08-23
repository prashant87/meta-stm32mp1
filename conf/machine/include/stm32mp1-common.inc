DEFAULTTUNE = "cortexa7thf-neon-vfpv4"

PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot-mainline"
PREFERRED_PROVIDER_virtual/kernel ??= "linux-mainline"

UBOOT_SUFFIX = "img"
UBOOT_ENTRYPOINT = "0xC2000040"

SERIAL_CONSOLES = "115200;ttySTM0"
SERIAL_CONSOLES_CHECK = "${SERIAL_CONSOLES}"

KERNEL_IMAGETYPE ?= "zImage"

# Do not update fstab file when using wic images
WIC_CREATE_EXTRA_ARGS ?= "--no-fstab-update"

# Image
IMAGE_FSTYPES += "tar.bz2 wic wic.gz wic.bmap"

WKS_FILE_DEPENDS ?= " \
    virtual/bootloader \
    e2fsprogs-native \
    bmap-tools-native \
"

# Wic default support
WKS_FILE ?= "stm32mp1.wks"