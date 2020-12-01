#ifndef CRC8_H
#define CRC8_H

/* C library */
#include <stddef.h>
#include <stdint.h>

class crc8 {
public:
	crc8(const uint8_t polynomial, const uint8_t seed);
	uint8_t process(const uint8_t * const data, const size_t length);
private:
	uint8_t m_polynomial;
	uint8_t m_crc;
};

#endif
