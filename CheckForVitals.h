#pragma once
#include "./PrintMessage.h"
#include "./monitor.h"
#include <String>

bool isInRange(float value, float minimum, float maximum);
bool isTemperatureInRange(float temperature, Language lang);
bool isPulseRateInRange(float pulseRate, Language lang);
bool isSpo2InRange(float spo2, Language lang);

bool checkAndDisplay(float value, float lowerLimit, float upperLimit, 
	const std::string& messageBelow, const std::string& messageAbove);
bool isBelowLowerLimit(float value, float lowerLimit, const std::string& message);
bool isApproachingLimit(float value, float limit, float tolerance, const std::string& message);
bool isAboveUpperLimit(float value, float upperLimit, const std::string& message);
