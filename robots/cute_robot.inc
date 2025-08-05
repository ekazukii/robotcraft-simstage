define laser ranger(
	sensor(
		range [0.0 5.6]
		fov 120.0
		samples 120
	)

	color "blue"
	size [0.06 0.06 0.06]

	block(
		points 4
		point[0] [0 0]
		point[1] [0 1]
		point[2] [1 1]
		point[3] [1 0]
		z [0 1]
	)
)

define sidelaser ranger(
	sensor(
		range [0.0 5.6]
		fov 30.0
		samples 30
	)

	color "blue"
	size [0.06 0.06 0.06]

	block(
		points 4
		point[0] [0 0]
		point[1] [0 1]
		point[2] [1 1]
		point[3] [1 0]
		z [0 1]
	)
)

define simple_robot position(
	odom_error [0.03 0.03 0.00 0.05]
	localization "odom"
	size [0.4 0.3 0.2]
	gui_nose 1
	drive "diff"
	color "yellow"

	laser(pose [0.23 0.0 -0.15 0.0])
	sidelaser(pose [0.0 0.23 -0.15 74.0])
	sidelaser(pose [0.0 -0.23 -0.15 -74.0])
	

)
