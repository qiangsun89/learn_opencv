//
// Created by qiang on 2022/3/2.
//

#include <iostream>
#include "opencv2/opencv.hpp"
int main(int argc, char* argv[])
{
//    cv::Mat grayim(600, 800, CV_8UC1);
//    cv::Mat colorim(600, 800, CV_8UC3);
//    //遍历所有像素,并设置像素值
//    for( int i = 0; i < grayim.rows; ++i)
//        for( int j = 0; j < grayim.cols; ++j )
//            grayim.at<uchar>(i,j) = (i+j)%255;
//    //遍历所有像素,并设置像素值
//    for( int i = 0; i < colorim.rows; ++i)
//        for( int j = 0; j < colorim.cols; ++j )
//        {
//            cv::Vec3b pixel;
//            pixel[0] = i%255; //Blue
//            pixel[1] = j%255; //Green
//            pixel[2] = 0;
//            //Red
//            colorim.at<cv::Vec3b>(i,j) = pixel;
//        }

    //显示结果
//    cv::imshow("grayim", grayim);
//    cv::imshow("colorim", colorim);
//    cv::waitKey(0);

/*iterator*/
    cv::Mat grayim(600, 800, CV_8UC1);
    cv::Mat colorim(600, 800, CV_8UC3);
    //遍历所有像素,并设置像素值
    cv::MatIterator_<uchar> grayit, grayend;
    for(grayit=grayim.begin<uchar>(),grayend =grayim.end<uchar>(); grayit != grayend; ++grayit)
        *grayit = rand()%255;
    //遍历所有像素,并设置像素值
    cv::MatIterator_<cv::Vec3b> colorit, colorend;
    for(colorit=colorim.begin<cv::Vec3b>(),colorend=colorim.end<cv::Vec3b>(); colorit != colorend; ++colorit)
    {
        (*colorit)[0] = rand()%255; //Blue
        (*colorit)[1] = rand()%255; //Green
        (*colorit)[2] = rand()%255; //Red
    }
    //显示结果
    cv::imshow("grayim", grayim);
    cv::imshow("colorim", colorim);
    cv::waitKey(0);

    cv::Mat M(3,2, CV_8UC3, cv::Scalar(0,0,255));
    std::cout << "M = " << std::endl << " " << M << std::endl;
    cv::Mat Z = cv::Mat::zeros(2,3, CV_8UC1);
    std::cout << "Z = " << std::endl << " " << Z << std::endl;

    cv::Mat O = cv::Mat::ones(2, 3, CV_32F);
    std::cout << "O = " << std::endl << " " << O << std::endl;

    cv::Mat E = cv::Mat::eye(2, 3, CV_64F);
    std::cout << "E = " << std::endl << " " << E << std::endl;

    cv::Vec3b color; //用 color 变量描述一种 RGB 颜色
    color[0]=255; //B 分量
    color[1]=0; //G 分量
    color[2]=0; //R 分量
    return 0;
}

