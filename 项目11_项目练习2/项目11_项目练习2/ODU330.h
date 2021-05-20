#pragma once
#include <string>
#include "ODU.h"
class ODU330 : public ODU
{
public:
	ODU330();
	~ODU330();

	float getWarnThreshold();
	bool setWarnThreshold(float threshold);
	float getBER();  //获取当前误码率
	string description();

private:
	float warnThreshold;  //告警门限
};

