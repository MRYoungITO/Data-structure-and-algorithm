#pragma once
#include "FixedLine.h"
#include "MobilePhone.h"

class WirelessTel : public FixedLine, public MobilePhone
{
public:
	void setNumber(const char* number);
	string getNumber() const;
};

