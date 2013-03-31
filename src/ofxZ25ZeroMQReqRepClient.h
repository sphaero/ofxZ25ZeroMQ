#ifndef _OFXZEROMQREQREPCLIENT_H
#define _OFXZEROMQREQREPCLIENT_H

//#include <deque>
//#include <pthread.h>
#include <zmq.hpp>
#include <string>

class ofxZ25ZeroMQReqRepClient
{
public:
    ofxZ25ZeroMQReqRepClient(zmq::context_t &context)
    {
        //_context = context;//new zmq::context_t(1);
        //_context = context;
        _socket  = new zmq::socket_t(context, ZMQ_REQ);
    }

    void setup(std::string connectUrl) {

        _socket->connect(connectUrl.c_str());
    }

    void request(std::string message) {

        zmq::message_t request(sizeof(message.c_str()));
        memcpy((void *) request.data(),message.c_str(), sizeof(message.c_str()));
        _socket->send(request);
        zmq::message_t reply;

        _socket->recv(&reply);
        char msg[reply.size()];
        memcpy(msg, reply.data(), reply.size());
        std::cout << "Received: " << reply.data() << " : "<< reply.size() << " : "<< msg << std::endl;
    }
    /*bool hasWaitingMessages();

protected:
    virtual void processMessage();

private:
    void shutdown();
    //void startThread();
    //void grabMutex();
    //void releaseMutex();
    */
    //zmq::context_t*  _context;
    zmq::socket_t*   _socket;
    //pthread_t thread;
    //pthread_mutex_t mutex;
};

#endif //_OFXZEROMQREQREPCLIENT_H
