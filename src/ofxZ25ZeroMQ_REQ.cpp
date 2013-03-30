#include "ofxZ25ZeroMQ_REQ.h"

//example:  https://github.com/jonnydee/nzmqt

ofxZ25ZeroMQ_REQ::ofxZ25ZeroMQ_REQ(zmq::context_t& context)
{
    _context =  context;
    _socket  =  new zmq::socket(context, ZMQ_REQ);
}

ofxZ25ZeroMQ_REQ::~ofxZ25ZeroMQ_REQ()
{
}

ofxZ25ZeroMQ_REQ::setup(string bindUrl)
{
    if ( _socket->connect(bindUrl) < 0 )
    {
        std::cout << "errors here" << std::endl;
	//http://api.zeromq.org/3-2:zmq-connect
    }
}

ofxZ25ZeroMQ_REQ::request(string message)
{
    _socket->send(message);
}
