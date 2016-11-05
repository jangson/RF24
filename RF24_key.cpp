
#include <avr/io.h>
#include <avr/interrupt.h>
#include "debug.h"
#include "nRF24L01.h"
#include "RF24_config.h"
#include "RF24.h"
#include "RF24_key.h"

#define RADIO_CHANNEL	100

RF24 radio;

const uint8_t pipe0[6] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};
const uint8_t pipe1[6] = {0xc2, 0xc2, 0xc2, 0xc2, 0xc2};
const uint8_t pipe2 = 0xc3;
const uint8_t pipe3 = 0xc4;
const uint8_t pipe4 = 0xc5;
const uint8_t pipe5 = 0xc6;

extern "C" void radio_init_key() {
	radio.begin();
	radio.setChannel(RADIO_CHANNEL);
	radio.setPALevel(RF24_PA_MAX);
	radio.setDataRate(RF24_2MBPS);
	radio.setCRCLength(RF24_CRC_16);
	radio.setAutoAck(1);                    // Ensure autoACK is enabled
	radio.enableDynamicPayloads();
	// radio.enableAckPayload();               // Allow optional ack payloads
    // radio.enableDynamicAck();

	radio.openWritingPipe(pipe0); // open pipe0 for writing

    // radio.openReadingPipe(0, pipe0); // open pipe0 for reading
    // radio.openReadingPipe(1, pipe1); // open pipe0 for reading
    // radio.openReadingPipe(2, &pipe2); // open pipe0 for reading
    // radio.openReadingPipe(3, &pipe3); // open pipe0 for reading
    // radio.openReadingPipe(4, &pipe4); // open pipe0 for reading
    // radio.openReadingPipe(5, &pipe5); // open pipe0 for reading

    // radio.printDetails();
}

extern "C" void radio_send_key(const uint8_t *report, uint8_t size)
{
	if (!radio.write(report, size)) {
        printf_P(PSTR("%s: write failed\n"), __func__);
    }
}

