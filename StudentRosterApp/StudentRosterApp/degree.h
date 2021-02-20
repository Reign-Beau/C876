#pragma once
#include <string>
#ifndef DEGREE_H
/* your original code */
#else
#define DEGREE_H
#endif

enum DegreeProgram : char {
    SECURITY, NETWORK, SOFTWARE, UNKNOWN
};

static const std::string degreeProgramAsString[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNKNOWN" };