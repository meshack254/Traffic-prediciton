#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function that predict traffic congestion level
std::string predictCongestion(double congestionIndex) {
    if (congestionIndex < 0.3) {
        return "Low congestion";
    }
    else if (congestionIndex < 0.7) {
        return "Moderate congestion";
    }
    else {
        return "High congestion";
    }
}

int main() {
    //Seed random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    //Simulate historical traffic data (congestion index between 0.0 and 1.0)
    std::vector<double> historicalData = { 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.4, 0.3, 0.9, 1.0 };

    //Simulate real-time sensor data (congestion index between 0.0 and 1.0)
    double realTimeData = static_cast<double>(std::rand()) / RAND_MAX;

    //Train the model
    double sum = 0.0;
    for (double data : historicalData) {
        sum += data;
    }
    double averageCongestion = sum / historicalData.size();

    //Prediction calculation
    double prediction = (averageCongestion + realTimeData) / 2.0;
    std::string congestionLevel = predictCongestion(prediction);

    // Return prediction
    std::cout << "Historical average congestion: " << averageCongestion << std::endl;
    std::cout << "Real-time congestion: " << realTimeData << std::endl;
    std::cout << "Predicted congestion: " << prediction << std::endl;
    std::cout << "Congestion level: " << congestionLevel << std::endl;

    return 0;
}
