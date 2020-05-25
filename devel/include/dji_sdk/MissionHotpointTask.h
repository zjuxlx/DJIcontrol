// Generated by gencpp from file dji_sdk/MissionHotpointTask.msg
// DO NOT EDIT!


#ifndef DJI_SDK_MESSAGE_MISSIONHOTPOINTTASK_H
#define DJI_SDK_MESSAGE_MISSIONHOTPOINTTASK_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dji_sdk
{
template <class ContainerAllocator>
struct MissionHotpointTask_
{
  typedef MissionHotpointTask_<ContainerAllocator> Type;

  MissionHotpointTask_()
    : latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , radius(0.0)
    , angular_speed(0.0)
    , is_clockwise(0)
    , start_point(0)
    , yaw_mode(0)  {
    }
  MissionHotpointTask_(const ContainerAllocator& _alloc)
    : latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , radius(0.0)
    , angular_speed(0.0)
    , is_clockwise(0)
    , start_point(0)
    , yaw_mode(0)  {
  (void)_alloc;
    }



   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _altitude_type;
  _altitude_type altitude;

   typedef double _radius_type;
  _radius_type radius;

   typedef float _angular_speed_type;
  _angular_speed_type angular_speed;

   typedef uint8_t _is_clockwise_type;
  _is_clockwise_type is_clockwise;

   typedef uint8_t _start_point_type;
  _start_point_type start_point;

   typedef uint8_t _yaw_mode_type;
  _yaw_mode_type yaw_mode;





  typedef boost::shared_ptr< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> const> ConstPtr;

}; // struct MissionHotpointTask_

typedef ::dji_sdk::MissionHotpointTask_<std::allocator<void> > MissionHotpointTask;

typedef boost::shared_ptr< ::dji_sdk::MissionHotpointTask > MissionHotpointTaskPtr;
typedef boost::shared_ptr< ::dji_sdk::MissionHotpointTask const> MissionHotpointTaskConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dji_sdk::MissionHotpointTask_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dji_sdk

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'dji_sdk': ['/home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5700988132c5f205ad38c15800896e84";
  }

  static const char* value(const ::dji_sdk::MissionHotpointTask_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5700988132c5f205ULL;
  static const uint64_t static_value2 = 0xad38c15800896e84ULL;
};

template<class ContainerAllocator>
struct DataType< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dji_sdk/MissionHotpointTask";
  }

  static const char* value(const ::dji_sdk::MissionHotpointTask_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 latitude  # degree\n\
float64 longitude # degree\n\
float64 altitude  # meter\n\
float64 radius    # meter\n\
float32 angular_speed #deg/s\n\
uint8 is_clockwise\n\
uint8 start_point\n\
uint8 yaw_mode\n\
";
  }

  static const char* value(const ::dji_sdk::MissionHotpointTask_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.radius);
      stream.next(m.angular_speed);
      stream.next(m.is_clockwise);
      stream.next(m.start_point);
      stream.next(m.yaw_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MissionHotpointTask_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dji_sdk::MissionHotpointTask_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dji_sdk::MissionHotpointTask_<ContainerAllocator>& v)
  {
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<double>::stream(s, indent + "  ", v.altitude);
    s << indent << "radius: ";
    Printer<double>::stream(s, indent + "  ", v.radius);
    s << indent << "angular_speed: ";
    Printer<float>::stream(s, indent + "  ", v.angular_speed);
    s << indent << "is_clockwise: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_clockwise);
    s << indent << "start_point: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.start_point);
    s << indent << "yaw_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.yaw_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DJI_SDK_MESSAGE_MISSIONHOTPOINTTASK_H
