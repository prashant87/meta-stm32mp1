# Copyright (C) 2019 Koncepto
# Released under the MIT license (see COPYING.MIT for the terms)

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=30503fd321432fc713238f582193b78e"

DEPENDS += "bison-native"

SRC_URI = " \
	git://gitlab.denx.de/u-boot/u-boot.git;protocol=https \
	file://0001-remove-usb-power.patch \
	file://0001-stm32mp1-Replace-ENV_IS_EXT4-to-MMC.patch \
	file://0002-stm32mp1-Enable-redundant-environment.patch \
"

SRCREV = "${AUTOREV}"

PV = "v2019.10+git${SRCPV}"

S = "${WORKDIR}/git"

UBOOT_MAKE_TARGET_append = " u-boot-initial-env"

do_install_append () {
	install -d ${D}/${sysconfdir}
	install -m 644 ${B}/u-boot-initial-env ${D}/${sysconfdir}/u-boot-initial-env
}

do_deploy_append () {
	install -d ${DEPLOYDIR}
	install -m 644 ${B}/u-boot-initial-env ${DEPLOYDIR}/u-boot-initial-env
}

PACKAGES =+ "${PN}-initial-env"
FILES_${PN}-initial-env = "${sysconfdir}/u-boot-initial-env"