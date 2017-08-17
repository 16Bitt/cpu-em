#include <cstdint>
#include "Ram.hpp"
#include "MMU16.hpp"

MMU16::MMU16(Ram *ram) {
	this->mMemory = ram;
}

MMU16::~MMU16() {
}


uint8_t MMU16::read8(segment16_t segment, addr16_t addr) {
	auto fullAddress = this->translateAddress(segment, addr);
	return this->mMemory->read8(fullAddress);
}

uint16_t MMU16::read16(segment16_t segment, addr16_t addr) {
	auto fullAddress = this->translateAddress(segment, addr);
	return this->mMemory->read16(fullAddress);
}


void MMU16::write8(segment16_t segment, addr16_t addr, uint8_t value) {
	auto fullAddress = this->translateAddress(segment, addr);
	this->mMemory->write8(fullAddress, value);
}

void MMU16::write16(segment16_t segment, addr16_t addr, uint16_t value) {
	auto fullAddress = this->translateAddress(segment, addr);
	this->mMemory->write16(fullAddress, value);
}

ramAddr_t MMU16::translateAddress(segment16_t segment, addr16_t addr) {
	auto actualSegment = static_cast<ramAddr_t>(segment);
	auto actualAddr = static_cast<ramAddr_t>(addr);

	return (actualSegment << 4) + actualAddr; 
}
