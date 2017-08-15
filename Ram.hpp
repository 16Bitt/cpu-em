#ifndef RAM_HPP
#define RAM_HPP

#include <cstdint>

typedef uint64_t ramAddr_t;

class Ram {
public:
	Ram(ramAddr_t size);
	~Ram();

	//Read data from ram
	uint8_t read8(ramAddr_t addr);
	uint16_t read16(ramAddr_t addr);
	uint32_t read32(ramAddr_t addr);
	
	//Write data to ram
	void write8(ramAddr_t addr, uint8_t value);
	void write16(ramAddr_t addr, uint16_t value);
	void write32(ramAddr_t addr, uint32_t value);

private:
	void *mBytes;
	uint8_t* getPtr8(ramAddr_t addr);
	uint16_t* getPtr16(ramAddr_t addr);
	uint32_t* getPtr32(ramAddr_t addr);
};

#endif
