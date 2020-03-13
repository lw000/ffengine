#pragma once

class Service {
public:
	virtual ~Service() {};

	virtual bool init() = 0;
	virtual bool start() = 0;
	virtual void stop() = 0;
};