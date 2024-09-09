#include "./PrintMessage.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <map>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

Language currentLanguage = ENGLISH;

std::map<Language, std::map<std::string, std::string>> messages = {
    {ENGLISH, {
        {"HYPO_THERMIA", "Temperature is critical!"},
        {"NEAR_HYPO", "Warning: Approaching hypothermia"},
        {"NORMAL", "Temperature is normal."},
        {"NEAR_HYPER", "Warning: Approaching hyperthermia"},
        {"HYPER_THERMIA", "Temperature is critical!"},
        {"PULSE_LOW", "Pulse Rate is too low!"},
        {"NEAR_PULSE_LOW", "Warning: Approaching low pulse rate"},
        {"PULSE_HIGH", "Pulse Rate is too high!"},
        {"NEAR_PULSE_HIGH", "Warning: Approaching high pulse rate"},
        {"SPO2_LOW", "Oxygen Saturation is too low!"},
        {"NEAR_SPO2_LOW", "Warning: Approaching low oxygen saturation"}
    }},
    {GERMAN, {
        {"HYPO_THERMIA", "Temperatur ist kritisch!"},
        {"NEAR_HYPO", "Warnung: Nahe Hypothermie"},
        {"NORMAL", "Temperatur ist normal."},
        {"NEAR_HYPER", "Warnung: Nahe Hyperthermie"},
        {"HYPER_THERMIA", "Temperatur ist kritisch!"},
        {"PULSE_LOW", "Pulsfrequenz ist zu niedrig!"},
        {"NEAR_PULSE_LOW", "Warnung: Nahe niedriger Pulsfrequenz"},
        {"PULSE_HIGH", "Pulsfrequenz ist zu hoch!"},
        {"NEAR_PULSE_HIGH", "Warnung: Nahe hoher Pulsfrequenz"},
        {"SPO2_LOW", "Sauerstoffsttigung ist zu niedrig!"},
        {"NEAR_SPO2_LOW", "Warnung: Nahe niedriger Sauerstoffsttigung"}
    }}
};

void displayLoaderAndMessage(const std::string& key) {
    std::string message = messages[currentLanguage][key];
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

void setLanguage(Language lang) {
    currentLanguage = lang;
}
