#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>

namespace lsd_slam
{

class OutputImageStream
{
public:
    OutputImageStream(const std::string& topic_name);
    ~OutputImageStream();

    void publishImage(const cv::Mat& cv_image);

private:
    ros::NodeHandle nh_;
    std::string image_channel;
    image_transport::Publisher image_publisher;
    image_transport::ImageTransport image_transporter;

};

}
