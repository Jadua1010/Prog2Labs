//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.3
//=====================...........................=================================

#include "DrawContourMarchingBetter.h" 
# include <vector>
# include <algorithm>

// draw contour
void DrawContourMarchingBetter::drawContour(float threshold) {

    // Get x and y bounds
    int minX = -ui->sizeX / 2;
    int maxX = ui->sizeX / 2;
    int minY = -ui->sizeY / 2;
    int maxY = ui->sizeY / 2;

    int highestXContour = 0;
    int lowestXContour = 0;

    std::vector<Point> worklist = {};
    std::vector<std::vector<bool>> visitedlist(ui->sizeX, std::vector<bool>(ui->sizeY, 0));

    bool prevPixelWasLower = 0;


    // Loop through all X values left to right
    for (int x = minX / 2; x < maxX; x++)
    {
        // Set previous "above" location
        bool prevAbove = (blob->potential(x, minY) > threshold);
        // Loop through all Y values again left to right
        for (int y = minY; y < maxY; y++)
        {
            // Set current "above" location
            bool currentAbove = (blob->potential(x, y) > threshold);
            if (currentAbove != prevAbove)
            {
                // Add the pixel to be worked on
                worklist.push_back(Point(x, y));

                if (highestXContour < x)
                    highestXContour = x;

                else if (lowestXContour > x) {
                    lowestXContour = x;

                    if (highestXContour == 0) {
                        x = 0;
                        break;
                    }
                }
            }
            // Now update so we can loop agian
            prevAbove = currentAbove;
        }
        if (((int)worklist.size()) > 1)
            break;
    }

    // Continue processing pixels until they are all done for this shape
    while (((int)worklist.size()) > 0) {


        // Get a pixel
        auto pixel = worklist.back();

        bool hasHigher = 0;
        bool hasLower = 0;

        // Check the corners of the pixel whether they are higher AND lower than the threshold. Then its a contour
        for (float i = pixel.x - 0.5; i <= pixel.x + 0.5; i++) {
            for (float j = pixel.y - 0.5; j <= pixel.y + 0.5; j++) {

                if (blob->potential(i, j) < threshold)
                    hasLower = 1;
                else
                    hasHigher = 1;
            }
        }

        // Set it to visited and remove from worklist
        visitedlist[pixel.x - minX][pixel.y - minY] = 1;
        worklist.pop_back();

        // If not a contour, skip
        if (!hasHigher || !hasLower) {
            continue;
        }

        // Process a contour case here

        // Add to be drawn
        ui->drawPixel(pixel.x, pixel.y);

        // Loop though every neighbouring pixel and do some checks to ensure only new pixels are added to worklist
        for (int i = pixel.x - 1; i <= pixel.x + 1; i++) {
            for (int j = pixel.y - 1; j <= pixel.y + 1; j++) {

                // Is already visited
                if (visitedlist[i - minX][j - minY] != 0)
                    continue;

                auto newPixel = Point(i, j);

                bool flag = 0;
                // Is already added to the worklist
                for (auto item : worklist)
                {
                    if (item.x == i && item.y == j) {
                        flag = 1;
                        continue;
                    }
                }
                if (flag)
                    continue;

                // else, add it
                worklist.push_back(newPixel);
            }
        }
    }
}