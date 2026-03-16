//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.3
//=====================...........................=================================

// DrawContourMarchingBetter class derived from class
// DrawContour.
#ifndef DRAWCONTOURMARCHINGBETTER_H
#define DRAWCONTOURMARCHINGBETTER_H

#include "DrawContour.h" // DrawContour class declaration

// DrawContourMarchingBetter class definition
class DrawContourMarchingBetter : public DrawContour
{
public:
    // constructor
    DrawContourMarchingBetter(UI &ui, Blob &blob): DrawContour(ui, blob) {};

    // draw contour
    virtual void drawContour(float threshold);
}; // end class DrawContourMarchingBetter

#endif