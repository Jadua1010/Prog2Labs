//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.1
//=====================...........................=================================

// DrawContourScanning class derived from class
// DrawContour.
#ifndef DRAWCONTOURSCANNING_H
#define DRAWCONTOURSCANNING_H

#include "DrawContour.h" // DrawContour class declaration

// DrawContourScanning class definition
class DrawContourScanning : public DrawContour
{
public:
    // constructor
    DrawContourScanning(UI &ui, Blob &blob): DrawContour(ui, blob) {};

    // draw contour
    virtual void drawContour(float threshold);
}; // end class DrawContourScanning

#endif