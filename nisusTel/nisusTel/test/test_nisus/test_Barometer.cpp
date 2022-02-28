#include <Barometer.hpp>
#include <gtest/gtest.h>

TEST(test_Barometer, isActive_WhenCreatedWithoutParameters_ExpectedTrue){
    Barometer sensor;
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Barometer, isActive_WhenCreatedWithTrueParameter_ExpectedTrue){
    Barometer sensor(true);
    
    ASSERT_TRUE(sensor.isActive());
}

TEST(test_Barometer, isActive_WhenCreatedWithFalseParameter_ExpectedTrue){
    Barometer sensor(false);
    
    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Barometer, activate_WhenActivatedWhileDeactivated_ExpectedFalse)
{
    Barometer sensor;
    sensor.deactivate();

    ASSERT_FALSE(sensor.isActive());
}

TEST(test_Barometer, activate_WhenDeactivatedWhileActivated_ExpectedTrue)
{
    Barometer sensor(false);
    sensor.activate();

    ASSERT_TRUE(sensor.isActive());
}