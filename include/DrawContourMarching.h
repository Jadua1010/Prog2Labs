//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.2
//=====================...........................=================================

// DrawContourMarching class derived from class
// DrawContour.
#ifndef DRAWCONTOURMARCHING_H
#define DRAWCONTOURMARCHING_H

#include "DrawContour.h" // DrawContour class declaration

// DrawContourMarching class definition
class DrawContourMarching : public DrawContour
{
public:
    // constructor
    DrawContourMarching(UI &ui, Blob &blob): DrawContour(ui, blob) {};

    // draw contour
    virtual void drawContour(float threshold);
}; // end class DrawContourMarching

#endif