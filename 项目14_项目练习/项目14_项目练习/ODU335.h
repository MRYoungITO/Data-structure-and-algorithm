#pragma once
#include "ODU.h"
class ODU335 : public ODU
{
public:
	ODU335();

	virtual bool heartBeat() override;
};


