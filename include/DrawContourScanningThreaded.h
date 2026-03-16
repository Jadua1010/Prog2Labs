//=====================...........................=================================
// Authors : Wessel Vis & Josh Ben-Nathan
// Group : 8
// License : LGPL open source license
//
// Brief : Assignment 5.4
//=====================...........................=================================

// DrawContourScanningThreaded class derived from class
// DrawContour.
#ifndef DRAWCONTOURSCANNINGTHREADED_H
#define DRAWCONTOURSCANNINGTHREADED_H

#include "DrawContour.h" // DrawContour class declaration

// DrawContourScanningThreaded class definition
class DrawContourScanningThreaded : public DrawContour
{
public:
    // constructor
    DrawContourScanningThreaded(UI &ui, Blob &blob): DrawContour(ui, blob) {};

    // draw contour
    virtual void drawContour(float threshold);
}; // end class DrawContourScanningThreaded

#endif