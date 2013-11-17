#include <gtest/gtest.h>

#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/mdc.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/helpers/sleep.h>

#include "avlsearchtree.h"

using namespace log4cplus::helpers;
using namespace log4cplus;

int testKey[] =
{ 23, 3, 4, 65, 32, 87, 9, 6, 21, 10, 39, 42 };
double testValue[] =
{ 1324.12, 2314.12, 4325.32, 64432.123, 34.12, 23.12, 4545.768, 79.32, 675.12,
		234536.467, 765.453, 632.123, };
TEST(avlsearchtree, normal)
{
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("avl"));
    AVLSearchTree<int, double> bst;
    for (int i = 0; i < 12; i++) {
        bst.insert(testKey[i], testValue[i]);
    }
    LOG4CPLUS_DEBUG(logger, bst.toString());LOG4CPLUS_DEBUG(
		logger, bst.size());

EXPECT_EQ(bst.size(), 12);
    EXPECT_EQ(bst.height(), 4);

    // remove some node
    double value;
    LOG4CPLUS_DEBUG(logger, "befor remove 10");bst.remove(10, value);
    EXPECT_EQ(bst.height(), 4);
    EXPECT_EQ(bst.size(), 11);
    EXPECT_EQ(value, 234536.467);

    LOG4CPLUS_DEBUG(logger,
		"before remove 65");
bst.remove(65, value);
    EXPECT_EQ(value, 64432.123);

    bst.remove(6, value);
    EXPECT_EQ(value, 79.32);
    int rst = bst.find(6, value);
    EXPECT_EQ(rst, URANUS_EMPTY_TREE);

    bst.find(87, value);
    EXPECT_EQ(value, 23.12);
    rst = bst.find(65, value);
    EXPECT_EQ(rst, URANUS_EMPTY_TREE);

}

TEST(avlsearchtree, removeRoot)
{
    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("avl"));
    AVLSearchTree<int, double> bst;
    for (int i = 0; i < 12; i++) {
        bst.insert(testKey[i], testValue[i]);
    }

    // remove root
    double value;
    bst.remove(87, value);

    // insert something
    bst.insert(2, 432.214);
    bst.insert(29, 23151.123);
    EXPECT_EQ(bst.height(), 5);
    LOG4CPLUS_DEBUG(logger, bst.toString()); }

int main(int argc, char *argv[])
{
log4cplus::initialize();
LogLog::getLogLog()->setInternalDebugging(true);
SharedObjectPtr<Appender> append(new ConsoleAppender());
append->setName(LOG4CPLUS_TEXT("First"));

log4cplus::getMDC().put(LOG4CPLUS_TEXT("key"), LOG4CPLUS_TEXT("MDC value"));
log4cplus::tstring pattern =
		LOG4CPLUS_TEXT(
				"%d{%m/%d/%y %H:%M:%S,%Q} [%t] %-5p %c{2} %%%x%% - %X{key} - %m [%l]%n");
append->setLayout(std::auto_ptr<Layout>(new PatternLayout(pattern)));
Logger::getRoot().addAppender(append);

testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
