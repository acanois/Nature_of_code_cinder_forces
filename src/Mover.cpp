//
//  Mover.cpp
//  Forces
//
//  Created by David Richter on 11/9/18.
//

#include "Mover.h"

Mover::Mover()
    : mass( 1.0f ),
      location( vec2( 0, 0 ) ),
      velocity( vec2( 0, 0 ) ),
      acceleration( vec2( 0, 0 ) )
{
    shader = gl::getStockShader( gl::ShaderDef().lambert().color() );
    mSphere = gl::Batch::create( geom::Sphere(), shader );
}

Mover::~Mover()
{
    
}

void Mover::applyForce( vec2 force )
{
    vec2 f = force / mass;
    acceleration += f;
}

void Mover::update()
{
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void Mover::display()
{
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    gl::pushModelMatrix();
    gl::translate(location);
    gl::color( Color( 1.0f, 1.0f, 1.0f ) );
    mSphere->draw();
    gl::popModelMatrix();
    
    gl::disableDepthRead();
    gl::disableDepthWrite();
}
