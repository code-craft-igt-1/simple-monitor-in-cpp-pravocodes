#pragma once

enum Language {
    ENGLISH,
    GERMAN
};

int vitalsOk(float temperature, float pulseRate, float spo2, bool isCelsius = true);
