#pragma once
#include <string>
#ifndef DEGREEH
#define DEGREEH

//Define an enumerated data type DegreeProgram containing the values SECURITY, NETWORK, and SOFTWARE.
enum class DegreeProgram{SECURITY,NETWORK,SOFTWARE};
static const std::string stringForDegreeProgram[] = { "SECURITY","NETWORK","SOFTWARE" };
#endif