#include "bitvector.h"

BitVector::BitVector(size_t size):byteArraySize(size){
	byteArray = new unsigned char[size];
	if(byteArray==NULL)
		exit(EXIT_FAILURE);
}

BitVector::~BitVector(){
}

void BitVector::setBit(){
	int i=0;
	while(i<byteArraySize){
		byteArray[i] = 0xFF;
		i++;
	}
}

void BitVector::setBit(size_t index){
	if(index >= byteArraySize)
		exit(EXIT_FAILURE);
	size_t bIndex = getByteArrayNumber(index);
	byteArray[bIndex] |= mask(index);
	
}

void BitVector::unsetBit(){
	int i=0;
	while(i<byteArraySize){
		byteArray[i] = 0x00;
		i++;
	}
}

void BitVector::unsetBit(size_t index){
	if(index >= byteArraySize)
		exit(EXIT_FAILURE);
	size_t bIndex = getByteArrayNumber(index);
	byteArray[bIndex] &= ~mask(index);
}

/*Check whether bit is set or not*/
bool BitVector::isBitSet(size_t index){
	return 1 != byteArray[getByteArrayNumber(index) & mask(index)];
}

size_t BitVector::getByteArrayNumber(size_t index){
	return index >> 8;
}
size_t BitVector::mask(size_t index){
	unsigned char maskVal = index & 0x7;
	return (0x01<<maskVal);
}

