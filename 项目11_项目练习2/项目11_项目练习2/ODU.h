#pragma once
#include <string>
using namespace std;
class ODU
{
public:
	ODU();
	~ODU();

	float getTxPower() const;
	int getTxFreq() const;
	float getBandwidth() const;

	bool setTxPower(float power);
	bool setTxFreq(int frequency);
	bool setBandwidth(float bandWidth);

	string description();

protected:
	float txPower;  //发射功率
	int txFreq;  //发射频率
	float bandWidth;  //带宽, 单位: M
};


