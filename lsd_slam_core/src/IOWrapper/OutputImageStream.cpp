#include "OutputImageStream.h"

namespace lsd_slam
{
OutputImageStream::OutputImageStream(const std::__cxx11::string& topic_name)
: image_transporter(nh_)
{
  std::string local_topic_name = "lsd_slam/" + topic_name;
  //image_transport::ImageTransport it(nh_);
  image_channel = nh_.resolveName(local_topic_name);
  image_publisher = image_transporter.advertise(image_channel, 1);
  
}

OutputImageStream::~OutputImageStream()
{

}


void OutputImageStream::publishImage(const cv::Mat& cv_image)
{
  cv_bridge::CvImage img_bridge;
  sensor_msgs::Image img_msg;
  
  try
  {
    std_msgs::Header header;
    header.seq = 0;
    header.stamp = ros::Time::now();
    img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, cv_image);
    img_bridge.toImageMsg(img_msg);
    image_publisher.publish(img_msg);
  }
  catch (cv_bridge::Exception e)
  {
  }

}

  
}