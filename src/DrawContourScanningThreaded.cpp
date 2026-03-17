//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.4
//=====================...........................=================================

#include "DrawContourScanningThreaded.h"
#include <thread>

// we can apparently create a vector of threads
#include <vector>

// include mutex because then it locks
#include <mutex>
std::mutex drawMutex;
// draw contour

void DrawContourScanningThreaded::drawThreadedContour(float threshold, int startY, int endY) {
    int minX = -ui->sizeX / 2;
    int maxX =  ui->sizeX / 2;

    // Loop through all Y values left to right but our Y is now startY and not minY because its pre determined
    for (int y = startY; y < endY; y++) {
        // Set previous "above" location
        bool prevAbove = (blob->potential(minX, y) > threshold);
        // Loop through all X values again left to right
        for (int x = minX + 1; x < maxX; x++) {
            // Set current "above" location
            bool currentAbove = (blob->potential(x, y) > threshold);

            if (currentAbove != prevAbove) {
                {
                // draw that pixel while locking the mutex so no other pixels can be drawn
                 std::lock_guard<std::mutex> lock(drawMutex);
                    ui->drawPixel(x, y);
                }
            }
            // Now update so we can loop agian
            prevAbove = currentAbove;
        }
    }
}
void DrawContourScanningThreaded::drawContour(float threshold) {

    int minY = -ui->sizeY / 2;
    int maxY =  ui->sizeY / 2;

    // How many threads to we ant, keep in mind that this depends on the CPU's performance
    int numThreads = 8;

    // Create a vector of threads
    std::vector<std::thread> threads;

    // Split the workload into chunks for each thread
    int chunk = (maxY - minY) / numThreads;

    // For loop for each dimension that the thread needs to work on
    for (int i = 0; i < numThreads; i++) {
        int startY = minY + i * chunk;
        int endY = (i == numThreads - 1) ? maxY : startY + chunk;

        // Create the thread with the specifications
        threads.emplace_back(
            &DrawContourScanningThreaded::drawThreadedContour,
            this,
            threshold,
            startY,
            endY
        );
    }

    // Wait for all threads to be done
    for (auto &t : threads) {
        t.join();
    }
}
