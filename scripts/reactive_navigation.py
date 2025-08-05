#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

class ReactiveNavigation:
    def __init__(self):
        rospy.loginfo("Controller starting: using /base_scan → /cmd_vel")

        # Publisher & Subscriber
        self.pub_cmd = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
        rospy.Subscriber('/base_scan', LaserScan, self.laser_callback)

        # State
        self.laser_msg = None
        self.rate = rospy.Rate(5)  # 5 Hz

    def laser_callback(self, msg):
        # Store the latest scan
        self.laser_msg = msg

    def run(self):
        while not rospy.is_shutdown():
            if self.laser_msg is None or not self.laser_msg.ranges:
                rospy.logwarn_throttle(5, "Waiting for valid laser scan...")
            else:
                cmd = Twist()
                # Find the closest obstacle
                dist = min(self.laser_msg.ranges)
                if dist > .8:
                    rospy.loginfo_throttle(1, f"Clear: moving (dist={dist:.2f})")
                    cmd.linear.x = 1.0
                else:
                    rospy.loginfo_throttle(1, f"Obstacle: turning (dist={dist:.2f})")
                    cmd.angular.z = 1.0
                self.pub_cmd.publish(cmd)

            self.rate.sleep()

if __name__ == '__main__':
    rospy.init_node('reactive_controller_py', anonymous=False)
    ReactiveNavigation().run()
