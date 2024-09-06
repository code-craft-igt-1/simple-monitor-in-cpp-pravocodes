#include "./monitor.h"
#include "./CheckForVitals.h"

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool isTemperatureOk = isTemperatureInRange(temperature);
    bool isPulseOk = isPulseRateInRange(pulseRate);
    bool isSpo2Ok = isSpo2InRange(spo2);
    return isTemperatureOk && isPulseOk && isSpo2Ok;
}
