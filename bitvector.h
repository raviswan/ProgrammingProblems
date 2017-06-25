#include <iostream>

class BitVector
{
public:
	BitVector(size_t size);
	void setBit();
	void setBit(size_t index);
	void unsetBit();
	void unsetBit(size_t index);
	/*Check whethe bit is set or not*/
	bool isBitSet(size_t index);
	~BitVector();
private:
	/*Get the byte number where the index is located*/
	size_t getByteArrayNumber(size_t index);
	size_t mask(size_t index);
	/*Actual byte array where each index stores 1 bit*/
	unsigned char* byteArray;
	size_t byteArraySize;
};