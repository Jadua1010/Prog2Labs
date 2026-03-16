//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.1
//=====================...........................=================================

#include "DrawContourScanning.h"

// draw contour
void DrawContourScanning::drawContour(float threshold)
{
    // Get x and y bounds
    int minX = -ui->sizeX / 2;
    int maxX =  ui->sizeX / 2;
    int minY = -ui->sizeY / 2;
    int maxY =  ui->sizeY / 2;

    // Loop through all Y values left to right
    for (int y = minY; y < maxY; y++)
    {
        // Set previous "above" location
        bool prevAbove = (blob->potential(minX, y) > threshold);
        // Loop through all X values again left to right
        for (int x = minX + 1; x < maxX; x++)
        {
            // Set current "above" location
            bool currentAbove = (blob->potential(x, y) > threshold);
            if (currentAbove != prevAbove)
            {
                // draw that pixel
                ui->drawPixel(x, y);
            }
            // Now update so we can loop agian
            prevAbove = currentAbove;
        }
    }
}