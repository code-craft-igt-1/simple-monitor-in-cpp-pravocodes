#include "./CheckForVitals.h"
#include "./PrintMessage.h"

bool CheckForRange(float value, float minimum, float maximum) {
    return (value >= minimum && value <= maximum);
}

bool CheckForTemperature(float temperature) {
    if (!CheckForRange(temperature, 95, 102)) {
        displayMessageandStars("Temperature is critical!");
        return false;
    }
    return true;
}

bool CheckForPulseRate(float pulseRate) {
    if (!CheckForRange(pulseRate, 60, 100)) {
        displayMessageandStars("Pulse Rate is out of range!");
        return false;
    }
    return true;
}

bool CheckForSpo2(float spo2) {
    if (spo2 < 90) {
        displayMessageandStars("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}
