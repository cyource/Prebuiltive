LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := prebuiltive
LOCAL_SRC_FILES := prebuiltive.cpp

LOCAL_STATIC_LIBRARIES := cpufeatures

LOCAL_CFLAGS += -fPIE -std=c++11
LOCAL_LDFLAGS += -fPIE -pie

include $(BUILD_EXECUTABLE)

$(call import-module,android/cpufeatures)