#include "./monitor.h"
#include "./CheckForVitals.h"

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool isTemperatureOk = CheckForTemperature(temperature);
    bool isPulseOk = CheckForPulseRate(pulseRate);
    bool isSpo2Ok = CheckForSpo2(spo2);
    return isTemperatureOk && isPulseOk && isSpo2Ok;
}
