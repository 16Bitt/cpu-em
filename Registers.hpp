#ifndef REGISTERS16_H
#define REGISTERS16_H

#include <cstdint>
#include "MMU16.hpp"

#define DECLARE_GPR(name) \
	template<typename T> T read_ ## name(); \
	template<typename T> void write_ ## name(T value); \


#define DEFINE_GPR(name) \
	template<typename T> \
	T Registers::read_ ## name() { \
		return reinterpret_cast<T>(this -> name); \
	} \
	\
	template<typename T>\
	void Registers::write_ ## name(T value) { \
		auto regPtr = reinterpret_cast<T*>(&(this->name)); \
		*regPtr = value; \
	} \


class Registers {
public:
	DECLARE_GPR(rax)
	DECLARE_GPR(rbx)
	DECLARE_GPR(rcx)
	DECLARE_GPR(rdx)
	DECLARE_GPR(rsp)
	DECLARE_GPR(rbp)
	DECLARE_GPR(rsi)
	DECLARE_GPR(rdi)
	DECLARE_GPR(r8)
	DECLARE_GPR(r9)
	DECLARE_GPR(r10)
	DECLARE_GPR(r11)
	DECLARE_GPR(r12)
	DECLARE_GPR(r13)
	DECLARE_GPR(r14)
	DECLARE_GPR(r15)

private:
	//Segments
	uint16_t ss, es, cs, ds, fs, gs;

	//General purpose
	uint64_t rax, rbx, rcx, rdx, rsp, rbp, rsi, rdi;
	uint64_t r8, r9, r10, r11, r12, r13, r14, r15;

	//Special
	uint32_t eflags;
	uint64_t rip;
};

#endif
