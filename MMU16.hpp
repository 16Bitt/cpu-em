#ifndef MMU16_HPP
#define MMU16_HPP

#include <cstdint>
#include "Ram.hpp"

typedef uint16_t segment16_t;
typedef uint16_t addr16_t;

class MMU16 {
public:
	MMU16(Ram *ram);
	~MMU16();

	uint8_t read8(segment16_t segment, addr16_t addr);
	uint16_t read16(segment16_t segment, addr16_t addr);

	void write8(segment16_t segment, addr16_t addr, uint8_t value);
	void write16(segment16_t segment, addr16_t addr, uint16_t value);

private:
	Ram *mMemory;
	ramAddr_t translateAddress(segment16_t segment, addr16_t addr);
};

#endif
