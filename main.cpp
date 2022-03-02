//
// Created by qiang on 2022/3/2.
//

#include <iostream>
#include "opencv2/opencv.hpp"
int main(int argc, char* argv[])
{
    cv::Mat grayim(600, 800, CV_8UC1);
    cv::Mat colorim(600, 800, CV_8UC3);
    //遍历所有像素,并设置像素值
    for( int i = 0; i < grayim.rows; ++i)
        for( int j = 0; j < grayim.cols; ++j )
            grayim.at<uchar>(i,j) = (i+j)%255;
    //遍历所有像素,并设置像素值
    for( int i = 0; i < colorim.rows; ++i)
        for( int j = 0; j < colorim.cols; ++j )
        {
            cv::Vec3b pixel;
            pixel[0] = i%255; //Blue
            pixel[1] = j%255; //Green
            pixel[2] = 0;
            //Red
            colorim.at<cv::Vec3b>(i,j) = pixel;
        }
    //显示结果
    cv::imshow("grayim", grayim);
    cv::imshow("colorim", colorim);
    cv::waitKey(0);

    cv::Mat M(3,2, CV_8UC3, cv::Scalar(0,0,255));
    std::cout << "M = " << std::endl << " " << M << std::endl;
    return 0;
}

