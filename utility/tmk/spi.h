
/**
 * @file spi.h
 * Class declaration for SPI helper files
 */

 /**
 * Example of spi.h class declaration for SPI portability
 *
 * @defgroup Porting_SPI Porting: SPI
 *
 * 
 * @{
 */
#include <string.h>
#include <stdint.h>
// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <getopt.h>
// #include <fcntl.h>
// #include <sys/ioctl.h>
#include <inttypes.h>
// #include <linux/types.h>
// #include <linux/spi/spidev.h> 

using namespace std;
class SPI {
public:

/**
	* SPI constructor
	*/	 
	SPI();
	
	/**
	* Start SPI
	*/
	void begin(void);
	
	/**
	* Transfer a single byte
	* @param tx_ Byte to send
	* @return Data returned via spi
	*/
	uint8_t transfer(uint8_t tx_);
	
	/**
	* Transfer a buffer of data
	* @param tbuf Transmit buffer
	* @param rbuf Receive buffer
	* @param len Length of the data
	*/
	void transfernb(uint8_t* tbuf, uint8_t* rbuf, uint8_t len);

	/**
	* Transfer a buffer of data without an rx buffer
	* @param buf Pointer to a buffer of data
	* @param len Length of the data
	*/	
	void transfern(uint8_t* buf, uint8_t len);
	
	virtual ~SPI();

    void enable(bool enable);

    uint8_t _SPI_TransferByte(const uint8_t Byte);
private:

	/** Default SPI device */
	/** SPI Mode set */
	uint8_t mode;
	/** word size*/
	uint8_t bits;
	/** Set SPI speed*/
	uint32_t speed;
	int fd;

	uint8_t caps;

	void init();	
};


/*@}*/
