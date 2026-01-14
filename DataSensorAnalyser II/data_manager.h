#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <vector>
#include <string>
#include "measurement.h"
#include "statistics.h"

class DataManager {
private:
    std::vector<Measurement> measurements;

public:
    // Data
    void addMeasurement(float value, const std::string& timestamp);
    const std::vector<Measurement>& getAll() const;
    void clear(); // extra enkel funktion

    // Statistik
    Statistics calculateStatistics() const;

    // Utskrift
    void printAll() const;
    void printStatistics() const;

    // Filhantering (KRAV) - ligger här nu, ingen file_io.* filer
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
};

#endif

