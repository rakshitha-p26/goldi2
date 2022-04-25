SUMMARY = "Provides a SVF-Player"
HOMEPAGE = "https://gitlab.tu-ilmenau.de/FakIA/fachgebiet-iks/goldi/goldi2/svf-player"
SRCREV = "${AUTOREV}"
SRC_URI = "git://git@gitlab.tu-ilmenau.de/FakIA/fachgebiet-iks/goldi/goldi2/svf-player.git;protocol=ssh;branch=development"
LICENSE = "LGPLv2.1"
LIC_FILES_CHKSUM = "file://LICENSE;md5=f2c6e854b04f73c7caa9a9ea48b57f1e"
SRC_URI[sha256sum] = "354ec4faf8359290f187fff0c513702747a3e2a3823a259978239e05f4e780cd"
S = "${WORKDIR}/git"

DEPENDS = "bcm2835 bison-native flex"

inherit meson
