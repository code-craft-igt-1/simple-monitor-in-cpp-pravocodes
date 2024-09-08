#include "./monitor.h"
#include "./CheckForVitals.h"
#include "./PrintMessage.h"

float convertToCelsius(float temperature, bool isCelsius) {
    return isCelsius ? temperature : (temperature - 32) * 5.0 / 9.0;
}

int vitalsOk(float temperature, float pulseRate, float spo2, bool isCelsius) {
    Language lang = ENGLISH;

    float tempInCelsius = convertToCelsius(temperature, isCelsius);

    bool isTemperatureOk = isTemperatureInRange(tempInCelsius, lang);
    bool isPulseOk = isPulseRateInRange(pulseRate, lang);
    bool isSpo2Ok = isSpo2InRange(spo2, lang);

    return isTemperatureOk && isPulseOk && isSpo2Ok;
}
