
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

int main()
{
    // Read and process Apple's data
    ifstream data("AAPL.csv");
    string line{};
    vector<vector<string>> AAPL; // Store Apple's data in a vector of vectors

    while (data && getline(data, line)) {
        // Tokenize the line and store the result in a vector using a range constructor of std::vector
        vector<string> row{ sregex_token_iterator(line.begin(), line.end(), comma, -1), sregex_token_iterator() };
        AAPL.push_back(row);
    }

    // Print Apple's data
    cout << "~ The Apple Data ~" << endl;
    for (int i = 1; i < AAPL.size(); i++) {
        for (int j = 0; j < AAPL[i].size(); j++) {
            cout << AAPL[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    int AppleDays = getNumberOfDays(AAPL); // Get the number of days in Apple's data
    cout << "Number of days in Apple's data: " << AppleDays << endl;
    cout << endl;
    cout << endl;

    // Read and process Microsoft's data
    cout << "~ The Microsoft Data ~" << endl;
    ifstream data2("MSFT.csv");
    string line2{};
    vector<vector<string>> MSFT; // Store Microsoft's data in a vector of vectors
    while (data2 && getline(data2, line2)) {
        // Tokenize the line and store the result in a vector using a range constructor of std::vector
        vector<string> row{ sregex_token_iterator(line2.begin(), line2.end(), comma, -1), sregex_token_iterator() };
        MSFT.push_back(row);
    }

    // Print Microsoft's data
    for (int i = 1; i < MSFT.size(); i++) {
        for (int j = 0; j < MSFT[i].size(); j++) {
            cout << MSFT[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    int MircoDays = getNumberOfDays(MSFT); // Get the number of days in Microsoft's data
    cout << "Number of days in Microsoft's data: " << MircoDays << endl;
    cout << endl;
    cout << endl;

    // Calculate the minimum and maximum values for Apple and Microsoft
    float minApple = min(AAPL); // Calculate the minimum value in Apple's data
    float minMicro = min(MSFT); // Calculate the minimum value in MicroSoft's data
    float maxApple = max(AAPL); // Calculate the maximum value in Apple's data
    float maxMicro = max(MSFT); // Calculate the maximum value in Microsoft's data

    cout << "Minimum of Apple: " << minApple << endl;
    cout << "Minimum of Microsoft: " << minMicro << endl;
    cout << "Maximum of Apple: " << maxApple << endl;
    cout << "Maximum of Microsoft: " << maxMicro << endl;

    // Calculate the mean of Apple and Microsoft's data
    float meanApple = mean(AAPL); // Calculate the mean of apple's data
    cout << "Apple's mean: " << meanApple << endl;
    float meanMSFT = mean(MSFT); // Calculate the mean of Microsoft's data
    cout << "Microsoft's mean: " << meanMSFT << endl;

    // Calculate the correlation between the adjusted close prices of apple and Microsoft
    vector<float> AAPlAdjClose;
    vector<float> MSFTAdjClose;

    // Extract the adjusted close prices from apple's data
    for (int i = 1; i < AAPL.size(); ++i) {
        float price = stof(AAPL[i][5]); // Convert the price from string to float
        AAPlAdjClose.push_back(price);
    }

    // Extract the adjusted close prices from Microsoft's data
    for (int i = 1; i < MSFT.size(); ++i) {
        float price = stof(MSFT[i][5]); // Convert the price from string to float
        MSFTAdjClose.push_back(price);
    }

    float correlationCoeff = correlation(AAPlAdjClose, MSFTAdjClose); // Calculate the correlation coefficient
    cout << "Correlation coefficient: " << correlationCoeff << endl;

    return 0;
}