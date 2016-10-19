
NRF24_DIR := $(TMK_DIR)/../RF24
DRIVER := utility/tmk

NRF24_SRC += \
	RF24.cpp \
	RF24_key.cpp \
	$(DRIVER)/spi.cpp \

SRC += $(NRF24_SRC)

VPATH += $(NRF24_DIR)
VPATH += $(NRF24_DIR)/$(DRIVER)
