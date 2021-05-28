#pragma once

class Computer;

class ComputerService
{
public:
	void upgrade(Computer* computer);
	void clean(Computer* computer);
	void kill(Computer* computer);
};

