define laser ranger(
    sensor(
        range [0.0 5.6]
        fov 240.0
        samples 240
    )
    color "blue"
    size [0.06 0.06 0.06]

    block( points 4
    point[0] [0 0]
    point[1] [0 1]
    point[2] [1 1]
    point[3] [1 0]
    z [0 1]
  )
)

define simple_robot position(
localization "odom"
odom_error [0.03 0.03 0.00 0.05]
size [1.35 1.05 0.90]
    origin [0 0 0 0]
    gui_nose 1
    drive "diff"
    color "dark green"

    # Corps principal du tank (forme rectangulaire)
    block( points 4
        point[0] [ 0.675 0.525 ]
        point[1] [ -0.675 0.525 ]
        point[2] [ -0.675 -0.525 ]
        point[3] [ 0.675 -0.525 ]
        z [0 0.45]
    )
    
    # Tourelle du tank (forme circulaire plus petite)
    block( points 12
        point[0] [ 0.360 0.000 ]
        point[1] [ 0.312 0.180 ]
        point[2] [ 0.180 0.312 ]
        point[3] [ 0.000 0.360 ]
        point[4] [ -0.180 0.312 ]
        point[5] [ -0.312 0.180 ]
        point[6] [ -0.360 0.000 ]
        point[7] [ -0.312 -0.180 ]
        point[8] [ -0.180 -0.312 ]
        point[9] [ 0.000 -0.360 ]
        point[10] [ 0.180 -0.312 ]
        point[11] [ 0.312 -0.180 ]
        z [0.45 0.75]
    )
    
    # Canon du tank
    block( points 4
        point[0] [ 1.050 0.045 ]
        point[1] [ 0.360 0.045 ]
        point[2] [ 0.360 -0.045 ]
        point[3] [ 1.050 -0.045 ]
        z [0.60 0.66]
    )
    
    laser(pose [0.90 0.0 -0.30 0.0])
)
