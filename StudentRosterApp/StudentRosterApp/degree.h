#pragma once
#include <string>

enum DegreeProgram : char {
    SECURITY, NETWORK, SOFTWARE, UNKNOWN
};

static const std::string degreeProgramAsString[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNKNOWN" };