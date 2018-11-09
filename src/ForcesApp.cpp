#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ForcesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    CameraPersp mCam;
    
    Mover ball;
};

void ForcesApp::setup()
{
    mCam.lookAt( vec3( 0, 0, 10 ), vec3( 0, 0, 0 ) );
}

void ForcesApp::mouseDown( MouseEvent event )
{
}

void ForcesApp::update()
{
}

void ForcesApp::draw()
{
    gl::setMatrices( mCam );
	gl::clear( Color( 0, 0, 0 ) );
    vec2 gravity = vec2(0.0f, -0.01f);
    ball.applyForce(gravity);
    ball.update();
    ball.display();
}

CINDER_APP( ForcesApp, RendererGl )
