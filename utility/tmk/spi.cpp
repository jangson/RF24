/*
 * spi.cpp
 *
 * Created: 20/1/2016 10:10:39
 *  Author: akatran
 */ 

#include <avr/io.h>
#include "debug.h"
#include "nRF24L01.h"
#include "RF24_config.h"
#include "LUFA/Drivers/Peripheral/SPI.h"

inline uint8_t SPI::_SPI_TransferByte(const uint8_t Byte)
{
    SPDR = Byte;
    // asm volatile("nop");
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

using namespace std;

void SPI::begin()
{
    init();
}

uint8_t SPI::transfer(uint8_t Byte)
{
    SPDR = Byte;
    while (!(SPSR & (1 << SPIF)));
    return SPDR;
}

void SPI::transfernb(uint8_t* tbuf, uint8_t* rbuf, uint8_t len)
{
    for (int i = 0; i < len; i++) {
        rbuf[i] = _SPI_TransferByte(tbuf[i]);
    }
}

void SPI::transfern(uint8_t* buf, uint8_t len)
{
    for (int i = 0; i < len; i++) {
        _SPI_TransferByte(buf[i]);
    }
}

void SPI::enable(bool enable)
{
    uint8_t SPIOptions = SPI_SPEED_FCPU_DIV_4 | SPI_ORDER_MSB_FIRST | SPI_SCK_LEAD_RISING | SPI_SAMPLE_LEADING | SPI_MODE_MASTER;

    if (enable) {
        /* pREVENT HIGH RISE TIMES ON pb.0 (/ss) FROM FORCING A CHANGE TO spi SLAVE MODE */
        DDRB  |= (1 << 0);
        PORTB |= (1 << 0);

        if (SPIOptions & SPI_USE_DOUBLESPEED)
          SPSR |= (1 << SPI2X);
        else
          SPSR &= ~(1 << SPI2X);

        /* Switch /SS to input mode after configuration to allow for forced mode changes */
        // DDRB &= ~(1 << 0);

        SPCR  = ((1 << SPE) | SPIOptions);

        DDRB  |=  ((1 << 1) | (1 << 2));
        DDRB  &= ~(1 << 3);
        PORTB |=  (1 << 3);

    } else {
        SPCR   = 0;
        SPSR   = 0;

        DDRB  &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3));
        PORTB |= ((1 << 0) | (1 << 1) | (1 <<2 ) | (1 << 3));
    }
}

void SPI::init()
{
    enable(true);
}

SPI::SPI()
{
	
}

SPI::~SPI()
{
 	
}

void operator delete(void * p) // or delete(void *, std::size_t)
{

}
