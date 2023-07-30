#include <iostream>
#include <vector>
#include <random>

// Function that predicts traffic congestion level
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
    // Seed random number generator with current time
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    // Simulate historical traffic data (congestion index between 0.0 and 1.0)
    std::vector<double> historicalData = { 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.4, 0.3, 0.9, 1.0 };

    // Check if historicalData is empty
    if (historicalData.empty()) {
        std::cerr << "Error: Historical data is empty." << std::endl;
        return 1;
    }

    // Simulate real-time sensor data (congestion index between 0.0 and 1.0)
    double realTimeData = dis(gen);

    // Train the model
    double sum = 0.0;
    for (double data : historicalData) {
        sum += data;
    }
    double averageCongestion = sum / historicalData.size();

    // Prediction calculation
    double prediction = (averageCongestion + realTimeData) / 2.0;
    std::string congestionLevel = predictCongestion(prediction);

    // Return prediction
    std::cout << "Historical average congestion: " << averageCongestion << std::endl;
    std::cout << "Real-time congestion: " << realTimeData << std::endl;
    std::cout << "Predicted congestion: " << prediction << std::endl;
    std::cout << "Congestion level: " << congestionLevel << std::endl;

    return 0;
}
