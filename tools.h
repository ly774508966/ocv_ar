/**
 * ocv_ar - OpenCV based Augmented Reality library
 *
 * Helper function class "Tools" -- header file.
 *
 * Authors: Markus Konrad <konrad@htw-berlin.de>, Alexander Godoba, June 2014.
 * INKA Research Group, HTW Berlin - http://inka.htw-berlin.de/
 *
 * This file contains code and inspiration from ArUco library developed at the
 * Ava group of the Univeristy of Cordoba (Spain).
 * See http://sourceforge.net/projects/aruco/
 *
 * See LICENSE for license.
 */

#ifndef OCV_AR_TOOLS_H
#define OCV_AR_TOOLS_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>

#include "types.h"

namespace ocv_ar {

/**
 * Misc. helper functions.
 */
class Tools {
public:
    /**
     * Return the distance between <p1> and <p2>.
     */
    static float distSquared(cv::Point2f p1, cv::Point2f p2);
    
    /**
     * Fast clock-wise rotation of <m> by 90°
     */
    static void matRot90CW(cv::Mat &m);
    
    /**
     * Get the avarage angle of an array of angles <angles> with
     * size <count>.
     */
    static float getAverageAngle(float *angles, int count);
    
    static void rotVecToQuat(const float r[3], float q[4]);
    static void quatToRotVec(float q[4], float r[3]);
    
    static float quatDot(const float q1[4], const float q2[4]);
    
//    /**
//     *
//     */
//    static void getAvgRotVec(const float *rotVecs, int numRotVecs, float *avgRotVec);
    
    /**
     * calculate a ModelView Matrix from camera rotation and position (vectors)
     */
    static void composeModelViewMatrix(float* camPos, float* camRot, float* matrixColumns);
    
    /**
     * Get current timestamp in milliseconds
     */
    static double nowMs();
    
    /**
     * Print matrix <m> with <rows> and <cols>.
     */
    static void printFloatMat(const float *m, int rows, int cols);
    
/* BEGIN code from ArUco lib */
    static float norm( float a, float b, float c );
    static float dot( float a1, float a2, float a3,
                     float b1, float b2, float b3 );
    static int  arParamDecompMat( float source[3][4], float cpara[3][4], float trans[3][4] );
/* END code from ArUco lib */
};
    
}

#endif