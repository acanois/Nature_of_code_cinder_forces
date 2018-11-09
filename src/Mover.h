//
//  Mover.hpp
//  Forces
//
//  Created by David Richter on 11/9/18.
//

#ifndef Mover_h
#define Mover_h

#include <iostream>

using namespace ci;
using namespace ci::app;
using namespace std;

class Mover {
public:
    Mover();
    ~Mover();
    
    void applyForce(vec2 force);
    void update();
    void display();

private:
    gl::BatchRef mSphere;
    gl::GlslProgRef shader;
    
    CameraPersp mCam;
    
    vec2 location;
    vec2 velocity;
    vec2 acceleration;
    
    float mass;
};

#endif /* Mover_h */
