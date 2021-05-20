#include <sstream>
#include "ODU.h"

ODU::ODU()
{

}

ODU::~ODU()
{

}

float ODU::getTxPower() const
{
	return txPower;
}

int ODU::getTxFreq() const
{
	return txFreq;
}

float ODU::getBandwidth() const
{
	return bandWidth;
}

bool ODU::setTxPower(float power)
{
	// 产品实际项目中, 是通过串口发送控制包实现的。
	txPower = power;
	return true;
}

bool ODU::setTxFreq(int frequency)
{
	txFreq = frequency;
	return true;
}

bool ODU::setBandwidth(float bandWidth)
{
	this->bandWidth = bandWidth;
	return true;
}

string ODU::description() {
	stringstream ret;
	ret << "发射功率: " << txPower << "\t发射频率: " << txFreq
		<< "\t带宽: " << bandWidth;
	return ret.str();
}
