#include <Gyroscope.hpp>
#include <gtest/gtest.h>

TEST(test_Gyroscope, isActive_WhenCreatedWithoutParameters_ExpectedTrue){
    Gyroscope sensor;
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Gyroscope, isActive_WhenCreatedWithTrueParameter_ExpectedTrue){
    Gyroscope sensor(true);
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Gyroscope, isActive_WhenCreatedWithFalseParameter_ExpectedTrue){
    Gyroscope sensor(false);
    
    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Gyroscope, activate_WhenActivatedWhileDeactivated_ExpectedFalse)
{
    Gyroscope sensor;
    sensor.deactivate();

    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Gyroscope, activate_WhenDeactivatedWhileActivated_ExpectedTrue)
{
    Gyroscope sensor(false);
    sensor.activate();

    ASSERT_TRUE(sensor.isActive());
}