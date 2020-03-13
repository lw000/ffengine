#pragma once

#include "../common/service.h"

class Network : public Service {
public:
	Network();
	~Network();

public:
	virtual bool init() override;
	virtual bool start() override;
	virtual void stop() override;
};