#include <gtest/gtest.h>
#include "dds_engine/Events/KeyEvent.h"

TEST(Event, EventCreation){
    dds::KeyPressedEvent* test_event = new dds::KeyPressedEvent(10 , 1);
    EXPECT_FALSE(test_event->Handled);
}
