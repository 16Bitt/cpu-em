#include "Ram.hpp"

Ram::Ram(ramAddr_t size) {
	this->mBytes = (void*) new uint8_t[size];
}

Ram::~Ram() {
	delete static_cast<uint8_t*>(this->mBytes);
}

uint8_t Ram::read8(ramAddr_t addr) {
	return *(this->getPtr8(addr));
}

uint16_t Ram::read16(ramAddr_t addr) {
	return *(this->getPtr16(addr));
}

uint32_t Ram::read32(ramAddr_t addr) {
	return *(this->getPtr32(addr));
}

void Ram::write8(ramAddr_t addr, uint8_t value) {
	*(this->getPtr8(addr)) = value;
}

void Ram::write16(ramAddr_t addr, uint16_t value) {
	*(this->getPtr16(addr)) = value;
}

void Ram::write32(ramAddr_t addr, uint32_t value) {
	*(this->getPtr32(addr)) = value;
}

uint8_t* Ram::getPtr8(ramAddr_t addr) {
	auto bytesAsPtr = static_cast<uint8_t*>(this->mBytes);
	return bytesAsPtr + addr;
}

uint16_t* Ram::getPtr16(ramAddr_t addr) {
	return reinterpret_cast<uint16_t*>(this->getPtr8(addr));
}

uint32_t* Ram::getPtr32(ramAddr_t addr) {
	return reinterpret_cast<uint32_t*>(this->getPtr8(addr));
}
