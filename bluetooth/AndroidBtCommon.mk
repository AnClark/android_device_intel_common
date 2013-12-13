include $(COMMON)/ComboChipVendor.mk

ifeq ($(COMBO_CHIP_VENDOR),bcm)
LIBBT_CONF_PATH := hardware/broadcom/libbt/conf/intel
include $(LIBBT_CONF_PATH)/Android.mk
endif

LOCAL_PATH := $(ANDROID_BUILD_TOP)

COMMON := device/intel/common
BT_COMMON := $(COMMON)/bluetooth

ifeq ($(COMBO_CHIP_VENDOR), intel) # Intel chip compilation flag
BOARD_USES_WCS := false
else
BOARD_USES_WCS := false
endif

##################################################

include $(CLEAR_VARS)
LOCAL_MODULE := bt_common
LOCAL_MODULE_TAGS := optional
LOCAL_REQUIRED_MODULES := \
	bd_prov \
	init.bt.rc \
	init.bt.vendor.rc \
	libbt-vendor \
	bt_vendor.conf \
	rfkill_bt.sh

include $(BUILD_PHONY_PACKAGE)

#################################################

include $(CLEAR_VARS)
LOCAL_MODULE := init.bt.rc
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)
LOCAL_SRC_FILES := $(BT_COMMON)/$(LOCAL_MODULE)
include $(BUILD_PREBUILT)

##################################################

include $(CLEAR_VARS)
LOCAL_MODULE := init.bt.vendor.rc
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)
LOCAL_SRC_FILES := $(BT_COMMON)/init.bt.$(COMBO_CHIP_VENDOR).rc
include $(BUILD_PREBUILT)

##################################################

include $(CLEAR_VARS)
LOCAL_MODULE := rfkill_bt.sh
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)
LOCAL_SRC_FILES := $(BT_COMMON)/rfkill_bt.sh
include $(BUILD_PREBUILT)

##################################################
