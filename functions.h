#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <regex>
#include <cmath>

float correlation(const std::vector<float>& x, const std::vector<float>& y);
float min(const std::vector<std::vector<std::string>>& currData);
float max(const std::vector<std::vector<std::string>>& currData);
float mean(const std::vector<std::vector<std::string>>& data);
int getNumberOfDays(const std::vector<std::vector<std::string>>& dataset);

#endif  // FUNCTIONS_H