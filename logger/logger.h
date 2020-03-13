#pragma once

#include <string>

class Logger {
public:
	Logger();
	~Logger();

public:
	bool start();
	void stop();

public:
	void debug(const std::string& format, ...);
	void info(const std::string& format, ...);
	void error(const std::string& format, ...);
};