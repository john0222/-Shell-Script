#ifndef DONGBEI_H
#define DONGBEI_H

#include <string>
#include <unordered_map>

class dongbeiConverter {
public:
    // Constructor
    NortheastShellConverter();

    // Destructor
    ~NortheastShellConverter();

    // Method to load conversion rules from a file
    bool loadConversionRules(const std::string& filename);

    // Method to convert Northeast dialect to Shell script
    std::string convertToShell(const std::string& northeastText) const;

    // Method to convert Shell script to Northeast dialect
    std::string convertToNortheast(const std::string& shellScript) const;

private:
    // Internal method to initialize conversion rules
    void initializeRules();

    // Maps for conversion rules
    std::unordered_map<std::string, std::string> northeastToShellMap;
    std::unordered_map<std::string, std::string> shellToNortheastMap;
};

#endif // DONGBEI_H
