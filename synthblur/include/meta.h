// Author: Patrick Wieschollek <mail@patwie.com>
#ifndef META_H
#define META_H

#include <vector>
#include <opencv2/core.hpp>

// 生成连续均匀分布的数值
template<typename T>
std::vector<float> linspace(T start_in, T end_in, const int num_in) {
    // static_cast 动态类型转换
    float start = static_cast<float>(start_in);
    float end = static_cast<float>(end_in);
    float num = static_cast<float>(num_in);
    float delta = (end - start) / (num - 1);

    std::vector<float> linspaced;
    for (int i = 0; i < num; ++i) {
        linspaced.push_back(start + delta * i);
    }
    // linspaced.push_back(end);
    return linspaced;
}

// 进行一个截断处理，让值处于 [lower, upper)中
template<typename T>
T clip(T val, T lower, T upper) {
    val = (val < upper) ? val : upper - 1;
    val = (val < lower) ? lower : val;
    return val;
}

// n张图片累加求均值
template<typename T>
T getMean(const std::vector<T>& images) {
    if (images.empty()) return T();

    // 初始化一个和图片同尺寸的累加器，开始值为0
    // 数据类型为 CV_32FC3，即每个像素有三个浮点数通道（表示 RGB 颜色）
    cv::Mat accumulator(images[0].rows, images[0].cols, CV_32FC3, float(0.));
    cv::Mat temp;

    for (int i = 0; i < images.size(); ++i) {
        images[i].convertTo(temp, CV_32FC3);
        accumulator += temp;
    }

    accumulator.convertTo(accumulator, CV_8U, 1. / images.size());
    return accumulator;
}

// 移除vector第一个元素
template<typename T>
void pop_front(std::vector<T>& vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

// 接受一张图片和缩放比例，返回缩放后的图片
cv::Mat scale(const cv::Mat input, float scale);

#endif