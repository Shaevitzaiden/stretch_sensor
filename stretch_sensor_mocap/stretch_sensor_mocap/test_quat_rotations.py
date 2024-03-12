#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.spatial.transform import Slerp

if __name__ == "__main__":
    # First run slerp to get array of quaternions
    
    num_interp_quats = 10
    times = np.linspace(0,1,num_interp_quats)
    unit_vectors = np.zeros([3, num_interp_quats])
    unit_vectors[0,:] = 1
    unit_vectors = np.transpose(unit_vectors)
    
    quat1 = [0, 0, 0.258819, 0.9659258]
    quat2 = [0, 0, 0.3826834, 0.9238795]
    
    node_quaternions = R.from_quat([quat1, quat2])
    slerp_object = Slerp([0, 1], node_quaternions)

    # Perform slerp, gets out [start, ...num_interp_quats-2..., End]
    quats = slerp_object(times)
    
    # Apply rotations to unit vectors
    rotated_vectors = quats.apply(unit_vectors)
    print(rotated_vectors)
    
    # Sequentially add vectors using cumulative sum
    summed_rotated_vectors = np.cumsum(rotated_vectors, axis=0)
    print(summed_rotated_vectors)