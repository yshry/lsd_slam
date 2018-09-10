#include <ros/ros.h>
#include <opencv2/opencv.hpp>

namespace lsd_slam
{

class OutputImageStream
{
public:
    OutputImageStream(const std::string& topic_name);
    ~OutputImageStream();

    void imageCb(const cv::Mat& cv_image);

private:
    ros::NodeHandle nh_;

};

}
