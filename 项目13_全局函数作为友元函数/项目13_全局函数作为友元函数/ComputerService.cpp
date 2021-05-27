#include "ComputerService.h"
#include "Computer.h"

void ComputerService::upgrade(Computer* computer)
{
	computer->cpu = "i9";
}
