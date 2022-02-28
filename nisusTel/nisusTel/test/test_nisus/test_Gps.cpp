#include <Gps.hpp>
#include <gtest/gtest.h>

TEST(test_Gps, isActive_WhenCreatedWithoutParameters_ExpectedTrue){
    Gps sensor;
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Gps, isActive_WhenCreatedWithTrueParameter_ExpectedTrue){
    Gps sensor(true);
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Gps, isActive_WhenCreatedWithFalseParameter_ExpectedTrue){
    Gps sensor(false);
    
    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Gps, activate_WhenActivatedWhileDeactivated_ExpectedFalse)
{
    Gps sensor;
    sensor.deactivate();

    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Gps, activate_WhenDeactivatedWhileActivated_ExpectedTrue)
{
    Gps sensor(false);
    sensor.activate();

    ASSERT_TRUE(sensor.isActive());
}