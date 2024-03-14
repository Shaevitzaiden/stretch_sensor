# generated from rosidl_generator_py/resource/_idl.py.em
# with input from stretch_sensor_msgs:msg/NodeMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'strain_adc'
# Member 'base_resistance'
# Member 'resistance'
# Member 'strain'
# Member 'base_length'
# Member 'length'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NodeMessage(type):
    """Metaclass of message 'NodeMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('stretch_sensor_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'stretch_sensor_msgs.msg.NodeMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__node_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__node_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__node_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__node_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__node_message

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NodeMessage(metaclass=Metaclass_NodeMessage):
    """Message class 'NodeMessage'."""

    __slots__ = [
        '_header',
        '_quaternion',
        '_euler_angles',
        '_rotation_quality',
        '_acceleration',
        '_gyroscope',
        '_strain_adc',
        '_base_resistance',
        '_resistance',
        '_strain',
        '_base_length',
        '_length',
        '_gain',
        '_frame',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'quaternion': 'geometry_msgs/Quaternion',
        'euler_angles': 'geometry_msgs/Vector3',
        'rotation_quality': 'int32',
        'acceleration': 'geometry_msgs/Vector3',
        'gyroscope': 'geometry_msgs/Vector3',
        'strain_adc': 'sequence<int64>',
        'base_resistance': 'sequence<double>',
        'resistance': 'sequence<double>',
        'strain': 'sequence<double>',
        'base_length': 'sequence<double>',
        'length': 'sequence<double>',
        'gain': 'int32',
        'frame': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int64')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Quaternion
        self.quaternion = kwargs.get('quaternion', Quaternion())
        from geometry_msgs.msg import Vector3
        self.euler_angles = kwargs.get('euler_angles', Vector3())
        self.rotation_quality = kwargs.get('rotation_quality', int())
        from geometry_msgs.msg import Vector3
        self.acceleration = kwargs.get('acceleration', Vector3())
        from geometry_msgs.msg import Vector3
        self.gyroscope = kwargs.get('gyroscope', Vector3())
        self.strain_adc = array.array('q', kwargs.get('strain_adc', []))
        self.base_resistance = array.array('d', kwargs.get('base_resistance', []))
        self.resistance = array.array('d', kwargs.get('resistance', []))
        self.strain = array.array('d', kwargs.get('strain', []))
        self.base_length = array.array('d', kwargs.get('base_length', []))
        self.length = array.array('d', kwargs.get('length', []))
        self.gain = kwargs.get('gain', int())
        self.frame = kwargs.get('frame', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.quaternion != other.quaternion:
            return False
        if self.euler_angles != other.euler_angles:
            return False
        if self.rotation_quality != other.rotation_quality:
            return False
        if self.acceleration != other.acceleration:
            return False
        if self.gyroscope != other.gyroscope:
            return False
        if self.strain_adc != other.strain_adc:
            return False
        if self.base_resistance != other.base_resistance:
            return False
        if self.resistance != other.resistance:
            return False
        if self.strain != other.strain:
            return False
        if self.base_length != other.base_length:
            return False
        if self.length != other.length:
            return False
        if self.gain != other.gain:
            return False
        if self.frame != other.frame:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def quaternion(self):
        """Message field 'quaternion'."""
        return self._quaternion

    @quaternion.setter
    def quaternion(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'quaternion' field must be a sub message of type 'Quaternion'"
        self._quaternion = value

    @builtins.property
    def euler_angles(self):
        """Message field 'euler_angles'."""
        return self._euler_angles

    @euler_angles.setter
    def euler_angles(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'euler_angles' field must be a sub message of type 'Vector3'"
        self._euler_angles = value

    @builtins.property
    def rotation_quality(self):
        """Message field 'rotation_quality'."""
        return self._rotation_quality

    @rotation_quality.setter
    def rotation_quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rotation_quality' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rotation_quality' field must be an integer in [-2147483648, 2147483647]"
        self._rotation_quality = value

    @builtins.property
    def acceleration(self):
        """Message field 'acceleration'."""
        return self._acceleration

    @acceleration.setter
    def acceleration(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'acceleration' field must be a sub message of type 'Vector3'"
        self._acceleration = value

    @builtins.property
    def gyroscope(self):
        """Message field 'gyroscope'."""
        return self._gyroscope

    @gyroscope.setter
    def gyroscope(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'gyroscope' field must be a sub message of type 'Vector3'"
        self._gyroscope = value

    @builtins.property
    def strain_adc(self):
        """Message field 'strain_adc'."""
        return self._strain_adc

    @strain_adc.setter
    def strain_adc(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'q', \
                "The 'strain_adc' array.array() must have the type code of 'q'"
            self._strain_adc = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -9223372036854775808 and val < 9223372036854775808 for val in value)), \
                "The 'strain_adc' field must be a set or sequence and each value of type 'int' and each integer in [-9223372036854775808, 9223372036854775807]"
        self._strain_adc = array.array('q', value)

    @builtins.property
    def base_resistance(self):
        """Message field 'base_resistance'."""
        return self._base_resistance

    @base_resistance.setter
    def base_resistance(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'base_resistance' array.array() must have the type code of 'd'"
            self._base_resistance = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'base_resistance' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._base_resistance = array.array('d', value)

    @builtins.property
    def resistance(self):
        """Message field 'resistance'."""
        return self._resistance

    @resistance.setter
    def resistance(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'resistance' array.array() must have the type code of 'd'"
            self._resistance = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'resistance' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._resistance = array.array('d', value)

    @builtins.property
    def strain(self):
        """Message field 'strain'."""
        return self._strain

    @strain.setter
    def strain(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'strain' array.array() must have the type code of 'd'"
            self._strain = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'strain' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._strain = array.array('d', value)

    @builtins.property
    def base_length(self):
        """Message field 'base_length'."""
        return self._base_length

    @base_length.setter
    def base_length(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'base_length' array.array() must have the type code of 'd'"
            self._base_length = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'base_length' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._base_length = array.array('d', value)

    @builtins.property
    def length(self):
        """Message field 'length'."""
        return self._length

    @length.setter
    def length(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'length' array.array() must have the type code of 'd'"
            self._length = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'length' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._length = array.array('d', value)

    @builtins.property
    def gain(self):
        """Message field 'gain'."""
        return self._gain

    @gain.setter
    def gain(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gain' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'gain' field must be an integer in [-2147483648, 2147483647]"
        self._gain = value

    @builtins.property
    def frame(self):
        """Message field 'frame'."""
        return self._frame

    @frame.setter
    def frame(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frame' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'frame' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._frame = value
