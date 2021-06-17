#include <iostream>
#include <string>
#include <sstream>
#include "ODU.h"

ODU::ODU()
{
	txFre = 34400;
	rxFre = 31100;
	txPower = 20;
	rxL = 0;
	type = ODU_TYPE::OUD_TYPE_331;

	cout << "调用ODU()" << endl;
}

int ODU::getTxFre()
{
	return txFre;
}

bool ODU::setTxFre(int frequence)
{
	txFre = frequence;
	cout << name() << "发射频率已经设置为" << txFre << "Hz" << endl;
	return true;
}

int ODU::getRxFre()
{
	return rxFre;
}

bool ODU::setRxFre(int frequence)
{
	rxFre = frequence;
	cout << name() << "接收频率已经设置为" << rxFre << "Hz" << endl;
	return true;
}

float ODU::getTxPower()
{
	return txPower;
}

bool ODU::setTxPower(float power)
{
	txPower = power;
	cout << name() << "发射功率已经设置为" << txPower << "dBm" << endl;
	return true;
}

float ODU::getRxL()
{
	return rxL;
}

bool ODU::heartBeat()
{
	cout << name() << "模拟串口协议读取数据: 获取心跳包的反馈. . .【"
		<< ODU_TYPE_331_FLAG << "】";
	string response;
	cin >> response;
	bool ret = false;

	if (response == ODU_TYPE_331_FLAG) {
		type = ODU_TYPE::OUD_TYPE_331;
		ret = true;
	}

	return ret;
}

string ODU::name()
{
	string ret;
	switch (type) {
	case ODU_TYPE::OUD_TYPE_331:
		ret = "ODU331";
		break;
	case ODU_TYPE::ODU_TYPE_335:
		ret = "ODU335";
		break;
	case ODU_TYPE::ODU_TYPE_UNKNOWN:
	default:
		ret = "ODU_UNKNOWN";
		break;
	}
	return ret;
}

ODU_TYPE ODU::getODUType()
{
	return type;
}
