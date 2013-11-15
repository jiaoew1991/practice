/*
 * LinkedList_test.cpp
 *
 *  Created on: 2013年11月1日
 *      Author: jiaoew
 */

#include "linkedlist.h"
#include <gtest/gtest.h>
#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/mdc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/helpers/sleep.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

TEST(normalTest, testInt)
{
    LinkedList<int> ll;
    for (int i = 0; i < 20; i++) {
        ll.append(i);
    }
    EXPECT_EQ(ll.leftLength(), 0);
    EXPECT_EQ(ll.rightLength(), 20);
    int value;
    ll.getValue(value);
    EXPECT_EQ(value, 0);

    EXPECT_EQ(ll.setPos(22), URANUS_INDEX_OUT_ARRAY);

    ll.setPos(5);
    ll.getValue(value);
    EXPECT_EQ(value, 5);

    ll.next();
    ll.next();
    ll.getValue(value);
    EXPECT_EQ(value, 7);

    ll.prev();
    ll.getValue(value);
    EXPECT_EQ(value, 6);
    
    ll.setEnd();
    ll.getValue(value);
    EXPECT_EQ(value, 6);

    ll.setStart();
    ll.getValue(value);
    EXPECT_EQ(value, 0);
    
    ll.clear();
    EXPECT_EQ(ll.leftLength(), 0);
    EXPECT_EQ(ll.rightLength(), 0);
}
TEST(outOfBundle, testInt)
{
    LinkedList<int> ll;
    for (int i = 0; i < 15; i++) {
        ll.append(i);
    }
    ll.insert(4);
    ll.setPos(1);
    ll.prev();
    int value;
    ll.getValue(value);
    EXPECT_EQ(value, 4);

    ll.setPos(13);
    for (int i = 0; i < 8; i++) {
        int rst = ll.remove(value);
        if (i < 3) {
            EXPECT_EQ(value, 12+i);
        } else {
            EXPECT_EQ(rst, URANUS_INDEX_OUT_ARRAY);
        }
    }
}
int main(int argc, char *argv[])
{
    log4cplus::initialize ();
    LogLog::getLogLog()->setInternalDebugging(true);

    SharedObjectPtr<Appender> append_1(new ConsoleAppender());
    append_1->setName(LOG4CPLUS_TEXT("First"));

    log4cplus::getMDC ().put (LOG4CPLUS_TEXT ("key"),
            LOG4CPLUS_TEXT ("MDC value"));
    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%d{%m/%d/%y %H:%M:%S,%Q} [%t] %-5p %c{2} %%%x%% - %X{key} - %m [%l]%n");
    //	std::tstring pattern = LOG4CPLUS_TEXT("%d{%c} [%t] %-5p [%.15c{3}] %%%x%% - %m [%l]%n");
    append_1->setLayout( std::auto_ptr<Layout>(new PatternLayout(pattern)) );
    Logger::getRoot().addAppender(append_1);

    Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("test.a.long_logger_name.c.logger"));
    LOG4CPLUS_DEBUG(logger, "This is the FIRST log message...");

    sleep(1, 0);
    {
        NDCContextCreator ndc(LOG4CPLUS_TEXT("second"));
        LOG4CPLUS_INFO(logger, "This is the SECOND log message...");
    }

    sleep(1, 0);
    LOG4CPLUS_WARN(logger, "This is the THIRD log message...");

    sleep(1, 0);
    LOG4CPLUS_ERROR(logger, "This is the FOURTH log message...");

    sleep(1, 0);
    LOG4CPLUS_FATAL(logger, "This is the FOURTH log message...");

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
