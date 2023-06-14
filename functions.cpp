#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <regex>
#include <cmath>
#include "functions.h" // Include the header file that declares the functions
using namespace std;

const std::regex comma(","); // Regular expression to split the CSV lines by commas

// Function to calculate the correlation coefficient between two vectors
float correlation(const std::vector<float>& x, const std::vector<float>& y)
{
    if (x.size() != y.size() || x.size() == 0) {
        // Invalid input, return 0 indicating no correlation
        return 0;
    }

    float sumX = 0;
    float sumY = 0;
    float sumXY = 0;
    float sumX2 = 0;
    float sumY2 = 0;

    int n = x.size();

    // Calculate the sums of x, y, x*y, x^2, and y^2
    for (int i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    // Calculate the correlation coefficient
    float numerator = (n * sumXY) - (sumX * sumY);
    float denominator = sqrt((n * sumX2 - sumX * sumX) * (n * sumY2 - sumY * sumY));

    if (denominator == 0) {
        // Handle division by zero case, return 0 indicating no correlation
        return 0;
    }

    float correlation = numerator / denominator;
    return correlation;
}

// Function to calculate the minimum value in a vector of vectors (representing data)
float min(const std::vector<std::vector<std::string>>& currData)
{
    float result = stof(currData[1][5]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][5]);
        if (result > curr)
        {
            result = curr;
        }
    }

    return result;
}

// Function to calculate the maximum value in a vector of vectors (representing data)
float max(const std::vector<std::vector<std::string>>& currData)
{
    float result = stof(currData[1][5]);
    for (int i = 2; i < currData.size(); ++i)
    {
        float curr = stof(currData[i][5]);
        if (result < curr)
        {
            result = curr;
        }
    }

    return result;
}

// Function to calculate the mean value of a vector of vectors (representing data)
float mean(const std::vector<std::vector<std::string>>& data)
{
    float result = stof(data[1][5]);
    int count = 1;
    for (int i = 2; i < data.size(); ++i)
    {
        result += stof(data[i][5]);
        ++count;
    }
    result = result / count;
    return result;
}

// Function to get the number of days in a vector of vectors (representing dataset)
int getNumberOfDays(const std::vector<std::vector<std::string>>& dataset)
{
    int count = 0;
    for (int i = 1; i < dataset.size(); ++i)
    {
        ++count;
    }
    return count;
}