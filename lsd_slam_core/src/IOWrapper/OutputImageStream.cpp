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

void OutputImageStream::publishImage(const cv::Mat& cv_image)
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    //cv_ptr = cv_bridge::
  }
  catch (cv_bridge::Exception e)
  {
  }

}

  
}