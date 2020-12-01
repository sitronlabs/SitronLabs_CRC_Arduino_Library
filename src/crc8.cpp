/* Self header */
#include <crc8.h>

crc8::crc8(const uint8_t polynomial, const uint8_t seed) {
	m_polynomial = polynomial;
	m_crc = seed;
}

uint8_t crc8::process(const uint8_t * const data, const size_t length) {
	for (size_t i = 0; i < length; i++) {
		m_crc ^= data[i];
		for (uint8_t j = 0; j < 8; j++) {
			if (m_crc & (1 << 7)) {
				m_crc = (m_crc << 1) ^ m_polynomial;
			} else {
				m_crc = (m_crc << 1);
			}
		}
	}

	/* Return crc */
	return m_crc;
}
