#include "data_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

void DataManager::addMeasurement(float value, const std::string& timestamp) {
    measurements.push_back({ value, timestamp });
}

const std::vector<Measurement>& DataManager::getAll() const {
    return measurements;
}

void DataManager::clear() {
    measurements.clear();
}

Statistics DataManager::calculateStatistics() const {
    Statistics s;
    if (measurements.empty()) return s;

    s.hasData = true;

    float sum = 0.0f;
    s.min = measurements[0].value;
    s.max = measurements[0].value;

    for (const auto& m : measurements) {
        sum += m.value;
        if (m.value < s.min) s.min = m.value;
        if (m.value > s.max) s.max = m.value;
    }

    s.average = sum / measurements.size();

    float sqSum = 0.0f;
    for (const auto& m : measurements) {
        float diff = m.value - s.average;
        sqSum += diff * diff;
    }

    // standardavvikelse (population)
    s.stddev = std::sqrt(sqSum / measurements.size());

    return s;
}

void DataManager::printAll() const {
    if (measurements.empty()) {
        std::cout << "No measured values ??are available.\n";
        return;
    }

    std::cout << "Measured values:\n";
    for (const auto& m : measurements) {
        std::cout << "- " << m.timestamp << " : " << m.value << "\n";
    }
}

void DataManager::printStatistics() const {
    Statistics s = calculateStatistics();
    if (!s.hasData) {
        std::cout << "No statistics (no data).\n";
        return;
    }

    std::cout << "\nStatistics:\n";
    std::cout << "Medel: " << s.average << "\n";
    std::cout << "Min:   " << s.min << "\n";
    std::cout << "Max:   " << s.max << "\n";
    std::cout << "Stdav: " << s.stddev << "\n"; //standardavvikelse
}

bool DataManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        // Fil finns inte ännu = ok
        return false;
    }

    measurements.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string timestamp, valueStr;

        // split på komma: timestamp,value
        if (!std::getline(ss, timestamp, ',')) continue;
        if (!std::getline(ss, valueStr)) continue;

        try {
            float value = std::stof(valueStr);
            measurements.push_back({ value, timestamp });
        }
        catch (...) {
            // hoppa över trasig rad
            continue;
        }
    }

    return true;
}

bool DataManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) return false;

    for (const auto& m : measurements) {
        file << m.timestamp << "," << m.value << "\n";
    }
    return true;
}
