#include "pch.h"

class TerribleLog
{
public:
	const int LogLevelError{ 0 };
	const int LogLevelWarning{ 1 };
	const int LogLevelInfo{ 2 }; 

private:
	int _LogLevel{ LogLevelInfo };

public:
	void SetLevel(int level)
	{
		_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (_LogLevel >= LogLevelError)
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]: " << message << std::endl;
	}

	void Info(const char* message)
	{
		if (_LogLevel >= LogLevelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}
};

void TestTerribleLogClass()
{
	TerribleLog log;
	log.SetLevel(log.LogLevelError);
	log.Error("Hello!");
	log.Warn("Hello!");
	log.Info("Hello!");
}