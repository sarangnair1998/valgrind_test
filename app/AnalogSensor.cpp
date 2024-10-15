#include <AnalogSensor.hpp>
#include <numeric>
#include <vector>

AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    // Declare the vector on the stack, not using new
    std::vector<int> readings(mSamples, 10);  // Create a vector with 'mSamples' elements initialized to 10

    // Accumulate the readings and calculate the average
    double result = std::accumulate(readings.begin(), readings.end(), 0.0) / readings.size();

    // Return the result as an integer
    return static_cast<int>(result);
}
