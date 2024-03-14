# Header
std_msgs/Header header

# Orientation
geometry_msgs/Quaternion quaternion
geometry_msgs/Point position
geometry_msgs/Vector3 euler_angles
int32 rotation_quality

# Accelerometer
geometry_msgs/Vector3 acceleration

# Gyroscope
geometry_msgs/Vector3 gyroscope

# Strain sensor
int64[] strain_adc
float64[] base_resistance
float64[] resistance
float64[] strain
float64[] base_length
float64[] length

# Gain
int32 gain

# Node frame
int64 frame
