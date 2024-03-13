// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__TRAITS_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stretch_sensor_msgs/msg/detail/node_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"
// Member 'euler_angles'
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace stretch_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodeMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: quaternion
  {
    out << "quaternion: ";
    to_flow_style_yaml(msg.quaternion, out);
    out << ", ";
  }

  // member: euler_angles
  {
    out << "euler_angles: ";
    to_flow_style_yaml(msg.euler_angles, out);
    out << ", ";
  }

  // member: rotation_quality
  {
    out << "rotation_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation_quality, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    to_flow_style_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: gyroscope
  {
    out << "gyroscope: ";
    to_flow_style_yaml(msg.gyroscope, out);
    out << ", ";
  }

  // member: strain_adc
  {
    if (msg.strain_adc.size() == 0) {
      out << "strain_adc: []";
    } else {
      out << "strain_adc: [";
      size_t pending_items = msg.strain_adc.size();
      for (auto item : msg.strain_adc) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: base_resistance
  {
    if (msg.base_resistance.size() == 0) {
      out << "base_resistance: []";
    } else {
      out << "base_resistance: [";
      size_t pending_items = msg.base_resistance.size();
      for (auto item : msg.base_resistance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: resistance
  {
    if (msg.resistance.size() == 0) {
      out << "resistance: []";
    } else {
      out << "resistance: [";
      size_t pending_items = msg.resistance.size();
      for (auto item : msg.resistance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: strain
  {
    if (msg.strain.size() == 0) {
      out << "strain: []";
    } else {
      out << "strain: [";
      size_t pending_items = msg.strain.size();
      for (auto item : msg.strain) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: base_length
  {
    if (msg.base_length.size() == 0) {
      out << "base_length: []";
    } else {
      out << "base_length: [";
      size_t pending_items = msg.base_length.size();
      for (auto item : msg.base_length) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: length
  {
    if (msg.length.size() == 0) {
      out << "length: []";
    } else {
      out << "length: [";
      size_t pending_items = msg.length.size();
      for (auto item : msg.length) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: gain
  {
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << ", ";
  }

  // member: frame
  {
    out << "frame: ";
    rosidl_generator_traits::value_to_yaml(msg.frame, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodeMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: quaternion
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quaternion:\n";
    to_block_style_yaml(msg.quaternion, out, indentation + 2);
  }

  // member: euler_angles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "euler_angles:\n";
    to_block_style_yaml(msg.euler_angles, out, indentation + 2);
  }

  // member: rotation_quality
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rotation_quality: ";
    rosidl_generator_traits::value_to_yaml(msg.rotation_quality, out);
    out << "\n";
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration:\n";
    to_block_style_yaml(msg.acceleration, out, indentation + 2);
  }

  // member: gyroscope
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyroscope:\n";
    to_block_style_yaml(msg.gyroscope, out, indentation + 2);
  }

  // member: strain_adc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.strain_adc.size() == 0) {
      out << "strain_adc: []\n";
    } else {
      out << "strain_adc:\n";
      for (auto item : msg.strain_adc) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: base_resistance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.base_resistance.size() == 0) {
      out << "base_resistance: []\n";
    } else {
      out << "base_resistance:\n";
      for (auto item : msg.base_resistance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: resistance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.resistance.size() == 0) {
      out << "resistance: []\n";
    } else {
      out << "resistance:\n";
      for (auto item : msg.resistance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: strain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.strain.size() == 0) {
      out << "strain: []\n";
    } else {
      out << "strain:\n";
      for (auto item : msg.strain) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: base_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.base_length.size() == 0) {
      out << "base_length: []\n";
    } else {
      out << "base_length:\n";
      for (auto item : msg.base_length) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.length.size() == 0) {
      out << "length: []\n";
    } else {
      out << "length:\n";
      for (auto item : msg.length) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << "\n";
  }

  // member: frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame: ";
    rosidl_generator_traits::value_to_yaml(msg.frame, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodeMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace stretch_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use stretch_sensor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stretch_sensor_msgs::msg::NodeMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  stretch_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stretch_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const stretch_sensor_msgs::msg::NodeMessage & msg)
{
  return stretch_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stretch_sensor_msgs::msg::NodeMessage>()
{
  return "stretch_sensor_msgs::msg::NodeMessage";
}

template<>
inline const char * name<stretch_sensor_msgs::msg::NodeMessage>()
{
  return "stretch_sensor_msgs/msg/NodeMessage";
}

template<>
struct has_fixed_size<stretch_sensor_msgs::msg::NodeMessage>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stretch_sensor_msgs::msg::NodeMessage>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stretch_sensor_msgs::msg::NodeMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__TRAITS_HPP_
