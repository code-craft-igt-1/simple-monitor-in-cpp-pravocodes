#include "./CheckForVitals.h"
#include "./PrintMessage.h"

const float BASE_TOLERANCE = 0.015f;



bool isBelowLowerLimit(float value, float lowerLimit, const std::string& message) {
    if (value < lowerLimit) {
        displayLoaderAndMessage(message);
        return true;
    }
    return false;
}

bool isApproachingLimit(float value, float limit, float tolerance, const std::string& message) {
    if (value < limit + tolerance) {
        displayLoaderAndMessage(message);
        return true;
    }
    return false;
}

bool isAboveUpperLimit(float value, float upperLimit, const std::string& message) {
    if (value > upperLimit) {
        displayLoaderAndMessage(message);
        return true;
    }
    return false;
}

bool isExcedingLimit(float value, float upperLimit, float tolerance, 
    const std::string& message) {
    if (value > upperLimit - tolerance) {
        displayLoaderAndMessage(message);
        return true;
    }
    return false;
}

bool checkAndDisplay(float value, float lowerLimit, float upperLimit,
    const std::string& messageBelow, const std::string& messageAbove) {

    float tolerance = BASE_TOLERANCE * upperLimit;
    bool result = true;

    result &= !isBelowLowerLimit(value, lowerLimit, messageBelow);
    result &= !isApproachingLimit(value, lowerLimit, tolerance, messageBelow);
    result &= !isExcedingLimit(value, upperLimit, tolerance, messageAbove);
    result &= !isAboveUpperLimit(value, upperLimit, messageAbove);

    return result;
}


bool isTemperatureInRange(float temperature, Language lang) {
    return checkAndDisplay(
        temperature,
        95,
        102,
        "HYPO_THERMIA",
        "NEAR_HYPER" );
}

bool isPulseRateInRange(float pulseRate, Language lang) {
    return checkAndDisplay(
        pulseRate,
        60,
        100,
        "PULSE_LOW",
        "NEAR_PULSE_HIGH" );
}

bool isSpo2InRange(float spo2, Language lang) {
    return checkAndDisplay(
        spo2,
        90,
        100,
        "SPO2_LOW",
        "NEAR_SPO2_LOW" );
}
