#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.spatial.transform import Slerp

if __name__ == "__main__":
    # First run slerp to get array of quaternions
    sensor_length = 2*np.pi
    num_interp_quats = 500
    times = np.linspace(0,10,num_interp_quats)
    unit_vectors = np.zeros([3, num_interp_quats])
    unit_vectors[0,:] = 1*sensor_length/(num_interp_quats-1)
    unit_vectors = np.transpose(unit_vectors)
    
    rot1 = R.from_euler('xyz',[0,0,0])
    rot2 = R.from_euler('xyz',[0,0,90])
    rot3 = R.from_euler('xyz',[0,0,180])
    
    quat1 = rot1.as_quat()
    quat2 = rot2.as_quat()
    quat3 = rot3.as_quat()
    
    node_quaternions = R.from_quat([quat1, quat2, quat3])
    slerp_object = Slerp([0, 5, 10], node_quaternions)

    # Perform slerp, gets out [start, ...num_interp_quats-2..., End]
    quats = slerp_object(times)
    # print(quats.as_quat())
    # Apply rotations to unit vectors
    rotated_vectors = quats.apply(unit_vectors)
    # print(rotated_vectors)
    
    # Sequentially add vectors using cumulative sum
    summed_rotated_vectors = np.cumsum(rotated_vectors, axis=0)
    print(summed_rotated_vectors)
    
    num_vectors = len(summed_rotated_vectors[:])-1
    for i in range(num_vectors):
        (x0,y0,z0) = summed_rotated_vectors[i,:]
        (x1,y1,z1) = summed_rotated_vectors[i+1,:]
        plt.plot([x0, x1], [y0, y1])
        if i == 0:
            plt.plot(x0,y0,'*',markersize=10,color='green')
        if i == (num_vectors-1):
            plt.plot(x1,y1,'*',markersize=10,color='red')

    plt.show()
