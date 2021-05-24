/********************************************************************
 * ThreadCreate:  A class to encapsulate the creation and destruction
 * of a pthread.
 * Edward Charles Eberle <eberdeed@eberdeed.net>
 * April 2020 San Diego, California USA
 ********************************************************************/
#ifndef THREADCREATE_H
#define THREADCREATE_H

#include "../../datagen/include/commonheader.h"

//! Forward declaration.
struct ThreadInfo;
/** \class ThreadCreate:  A class to encapsulate the creation and destruction
 * of a pthread.
 */
class ThreadCreate
{
public:
    //! \brief Class global variables are assigned here.
    ThreadCreate(string threadName, vector<ThreadInfo>threadInfo);
    //! \brief The destruction of the class is echoed here.
    ~ThreadCreate();
    /* Functions */
    //! \brief Here the thread is created and execution begins.
    int execute(void* func(void*), int threadNum);
    //! \brief Threads are joined only after execution is complete.
    void joinThread(int threadNum);
    //! \brief Threads are cancelled at any time.
    void cancelThread(int threadNum);
    //! \brief accessor function to access thread information.
    ThreadInfo getInfo(int threadNum);
protected:
    //! \brief Debug information about the thread.
    void displayPthread(pthread_attr_t *attr, int threadNum);
    //! \brief Display an error message with and error code and exit.
    void handle_error_en(int en, string msg);
    //! \brief Display an error message without and error code and exit.
    void handle_error(string msg); 
    /* Variables */
    //! The pthread function response values.
    int s, i;
    //! A pthread function response quantity.
    size_t v;
    //! The vector of thread information.
    vector<ThreadInfo>tinfo;
    //! The address of the stack in memory.
    void *stkaddr;
    //! The scheduling parameter.
    sched_param sp;
    //! The thread attribute structure.
    pthread_attr_t *threadAttr;
    //! The number of threads to execute.
    int numThreads;
    //! The name of the current thread.
    string name;
    //! The debug flag.
    bool debug1 = false;
};

#endif //  THREADCREATE_H

