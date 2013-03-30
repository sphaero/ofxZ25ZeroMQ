#ifndef _ofxZ25ZeroMQRECEIVER_H
#define _ofxZ25ZeroMQRECEIVER_H

#include <deque>
#include <pthread.h>
#include <zmq.hpp>
#include <string>

class ofxZ25ZeroMQ_REQ
{
public:
    ofxZ25ZeroMQ_REQ(zmq::context_t& context);
    ~ofxZ25ZeroMQSender();

    void setup(string bindUrl);

    void request(string message);
    bool hasWaitingMessages();

protected:
    virtual void processMessage();

private:
    void shutdown();
    //void startThread();
    //void grabMutex();
    //void releaseMutex();

    zmq::context_t  _context;
    zmq::socket_t*   _socket;
    //pthread_t thread;
    //pthread_mutex_t mutex;
}

#endif
