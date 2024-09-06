#include "./CheckForVitals.h"
#include "./PrintMessage.h"

bool isInRange(float value, float minimum, float maximum) {
    return (value >= minimum && value <= maximum);
}

bool isTemperatureInRange(float temperature) {
    if (!isInRange(temperature, 95, 102)) {
        displayLoaderAndMessage("Temperature is critical!");
        return false;
    }
    return true;
}

bool isPulseRateInRange(float pulseRate) {
    if (!isInRange(pulseRate, 60, 100)) {
        displayLoaderAndMessage("Pulse Rate is out of range!");
        return false;
    }
    return true;
}

bool isSpo2InRange(float spo2) {
    if (spo2 < 90) {
        displayLoaderAndMessage("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}
