// Author: Patrick Wieschollek <mail@patwie.com>
#ifndef FLOW_H
#define FLOW_H

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/cudaoptflow.hpp>
#include <opencv2/cudaarithm.hpp>


class Flow {
  cv::Mat anchor;
  cv::cuda::GpuMat motion;
  // 一个指向光流对象的指针
  cv::Ptr<cv::cuda::FarnebackOpticalFlow> flow_estimator;

  cv::Vec3i colorWheel[55]; // 一个三元素对象，一般用于装RBG

 public:
  Flow();
  void compute(cv::Mat a, cv::Mat b);
  cv::Mat visualize();

  const cv::cuda::GpuMat& get() const;

  cv::Mat shift(const cv::Mat &img, float ratio);

  void initColorWheel();
  bool isFlowCorrect(cv::Point2f u);
  cv::Vec3b computeColor(float fx, float fy);
  cv::Mat blur(const cv::Mat &img, std::vector<float> ratios);

};
#endif