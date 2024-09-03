#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void displayMessageandStars(const std::string& message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}


bool CheckForRange(float value, float minimum, float maximum) {
    return (value >= minimum && value <= maximum);
}

bool printTemperatureMessage(float temperature) {
    if (!CheckForRange(temperature, 95, 102)) {
        displayMessageandStars("Temperature is critical!");
        return false;
    }
    return true;
}

bool printPulseRateMessage(float pulseRate) {
    if (!CheckForRange(pulseRate, 60, 100)) {
        displayMessageandStars("Pulse Rate is out of range!");
        return false;
    }
    return true;
}

bool printSpo2Message(float spo2) {
    if (spo2 < 90) {
        displayMessageandStars("Oxygen Saturation out of range!");
        return false;
    }
    return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool isTemperatureOk = printTemperatureMessage(temperature);
    bool isPulseOk = printPulseRateMessage(pulseRate);
    bool isSpo2Ok = printSpo2Message(spo2);
    return isTemperatureOk && isPulseOk && isSpo2Ok;
}
