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
	size [0.45 0.35 0.30]
    origin [0 0 0 0]
    gui_nose 1
    drive "diff"
	color "dark green"

	# Corps principal du tank (forme rectangulaire)
	block( points 4
        point[0] [ 0.225 0.175 ]
        point[1] [ -0.225 0.175 ]
        point[2] [ -0.225 -0.175 ]
        point[3] [ 0.225 -0.175 ]
        z [0 0.15]
    )
    
    # Tourelle du tank (forme circulaire plus petite)
    block( points 12
        point[0] [ 0.120 0.000 ]
        point[1] [ 0.104 0.060 ]
        point[2] [ 0.060 0.104 ]
        point[3] [ 0.000 0.120 ]
        point[4] [ -0.060 0.104 ]
        point[5] [ -0.104 0.060 ]
        point[6] [ -0.120 0.000 ]
        point[7] [ -0.104 -0.060 ]
        point[8] [ -0.060 -0.104 ]
        point[9] [ 0.000 -0.120 ]
        point[10] [ 0.060 -0.104 ]
        point[11] [ 0.104 -0.060 ]
        z [0.15 0.25]
    )
    
    # Canon du tank
    block( points 4
        point[0] [ 0.350 0.015 ]
        point[1] [ 0.120 0.015 ]
        point[2] [ 0.120 -0.015 ]
        point[3] [ 0.350 -0.015 ]
        z [0.20 0.22]
    )
	
	laser(pose [0.30 0.0 -0.10 0.0])
)
