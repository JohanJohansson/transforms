#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <math.h>

int main(int argc, char **argv) {

    ros::init(argc, argv, "camera_tf_broadcaster");

    ros::NodeHandle n;

    static tf::TransformBroadcaster br;
    tf::Transform transform;

    double angle = 14.5*M_PI/180;

    ros::Rate loop_rate(20.0);
    while (n.ok()) {
        transform.setOrigin(tf::Vector3(0.0, 0.05, 0.14));
        tf::Quaternion q;
        q.setEuler(0.0, angle, 0.0);
        transform.setRotation(q);

        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "robot_center", "camera"));
        loop_rate.sleep();
    }

    return 0;
}
