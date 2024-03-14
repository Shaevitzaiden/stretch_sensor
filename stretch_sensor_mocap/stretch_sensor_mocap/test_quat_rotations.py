#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.spatial.transform import Slerp

if __name__ == "__main__":
    # First run slerp to get array of quaternions
    sensor_lengths = [1, 2]
    num_interp_quats = 4
    # times = np.linspace(0,10,num_interp_quats)
    # unit_vectors = np.zeros([3, num_interp_quats])
    # unit_vectors[0,:] = 1*sensor_length/(num_interp_quats-1)
    # unit_vectors = np.transpose(unit_vectors)
    
    # rot1 = R.from_euler('xyz',[0,0,0])
    # rot2 = R.from_euler('xyz',[0,0,90])
    # rot3 = R.from_euler('xyz',[0,0,180])
    
    # quat1 = rot1.as_quat()
    # quat2 = rot2.as_quat()
    # quat3 = rot3.as_quat()
    
    # node_quaternions = R.from_quat([quat1, quat2, quat3])
    # slerp_object = Slerp([0, 5, 10], node_quaternions)

    # # Perform slerp, gets out [start, ...num_interp_quats-2..., End]
    # quats = slerp_object(times)
    # # print(quats.as_quat())
    # # Apply rotations to unit vectors
    # rotated_vectors = quats.apply(unit_vectors)
    # # print(rotated_vectors)
    
    # # Sequentially add vectors using cumulative sum
    # summed_rotated_vectors = np.cumsum(rotated_vectors, axis=0)
    # print(summed_rotated_vectors)
    
    ############################################################3
    sensor_lengths = [1, 2]
    num_interp_quats = 3
    
    # List comprehension of lists containing quaternion components for each sensor node
    quats_array = [[0, 0, i*0.1, 1.0] for i in range(len([1,2,3]))]
    print("\n quats array")
    print(quats_array)
    # Window where each 
    slerp_window = np.arange(len(quats_array)) 
    print("\n slerp window")
    print(slerp_window)
    node_quaternions = R.from_quat(quats_array)
    
    # Make slerp object from window and quaternions
    slerp_object = Slerp(slerp_window, node_quaternions)

    # Perform slerp with num_inter_quats between each quaternion, gets out [start, ...num_interp_quats-2..., End]
    times = np.linspace(0, slerp_window[-1], num_interp_quats*len(quats_array))
    print("\n times")
    print(times)
    print(len(times))
    quats = slerp_object(times)
    
    # Make vectors using vector corresponding to direction axis strain sensor is attached to
    x_vecs = np.zeros([num_interp_quats*len(quats_array), 3])
    x_vecs[:,1] = 1
    
    # Rotate vectors 
    rotated_x_vectors = quats.apply(x_vecs)
    
    # Cumulative sum of vectors to build out curve
    summed_rotated_x_vectors = np.cumsum(rotated_x_vectors, axis=0)
    print(" \n summed_rotated_vectors")
    print(summed_rotated_x_vectors)
    print(summed_rotated_x_vectors.shape)
    idx_multiplier = len(times)/(len(quats_array)-1)
    print(idx_multiplier)
    idxs = np.linspace(0, len(times), len(quats_array))-1
    idxs[0] = 0
    print(idxs)
    for i in range(len(quats_array)):
        print(summed_rotated_x_vectors[int(idxs[i])])
    # Scale the vectors by the length of the strain sensors divided by the number of segments
    
    # strain_scaled_rotated_x_vectors = *summed_rotated_x_vectors/(num_interp_quats-1)
    
    # num_vectors = len(summed_rotated_vectors[:])-1
    # for i in range(num_vectors):
    #     (x0,y0,z0) = summed_rotated_vectors[i,:]
    #     (x1,y1,z1) = summed_rotated_vectors[i+1,:]
    #     plt.plot([x0, x1], [y0, y1])
    #     if i == 0:
    #         plt.plot(x0,y0,'*',markersize=10,color='green')
    #     if i == (num_vectors-1):
    #         plt.plot(x1,y1,'*',markersize=10,color='red')

    # plt.show()
