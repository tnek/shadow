ARCHS = arm64 arm64e
TARGET=iphone:clang:14.5:14.5


CFLAGS="-Wno-error"
include $(THEOS)/makefiles/common.mk
SUBPROJECTS += dylib
SUBPROJECTS += preferencebundle
SUBPROJECTS += shdw
include $(THEOS_MAKE_PATH)/aggregate.mk
