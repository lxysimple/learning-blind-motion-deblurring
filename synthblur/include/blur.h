// Author: Patrick Wieschollek <mail@patwie.com>
#ifndef BLUR_H
#define BLUR_H

#include <opencv2/opencv.hpp>

#include "flow.h"

// 一个接口
class Blur{
  public:
    Blur(); // 初始化类
    // cv::Mat 一种矩阵类
    cv::Mat shift(const cv::Mat &anchor_, const Flow &flow_, float ratio);
};

#endif
