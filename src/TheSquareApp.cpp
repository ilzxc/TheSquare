#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SquareObject.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TheSquareApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
    
  private:
    shared_ptr< SquareObject > test;
    Rectf square_bounds;
    Rectf left_bounds, right_bounds;
};

void TheSquareApp::prepareSettings( Settings* settings )
{
    Window::Format window_format;
    window_format.setSize( 1200, 600 );
    window_format.setTitle( "The Square" );
    settings->setDefaultWindowFormat( window_format );
}

void TheSquareApp::setup()
{
    gl::enableAlphaBlending();
    test = make_shared< SquareObject >( "Paper-2.png" );

    /*
   square = make_shared< SquareTexture >( "Paper-2.png" );
   behavior = make_shared< SquareBehavior > ( square );
    
    Vec2f square_dimensions = square->getDimensions();
    square_bounds = Rectf( getWindowWidth()  / 2.f - square_dimensions.x / 2.f,
                           getWindowHeight() / 2.f - square_dimensions.y / 2.f,
                           getWindowWidth()  / 2.f + square_dimensions.x / 2.f,
                           getWindowHeight() / 2.f + square_dimensions.y / 2.f );
    left_bounds  = Rectf( 0.f, 0.f, getWindowWidth() / 2.f, getWindowHeight() );
    right_bounds = Rectf( getWindowWidth() / 2.f, 0.f, getWindowWidth(), getWindowHeight() );
     */
}

void TheSquareApp::mouseDown( MouseEvent event )
{
    test->interact();
    /*
    bool check_left_right = true;
    
    if ( square_bounds.contains( event.getPos() ) )
    {
        cout << "checking for square bounds " << square->is_in( event.getPos() ) << endl;
        check_left_right = ! ( square->is_in( event.getPos() ) );
    }
    
    if ( check_left_right )
    {
        if ( left_bounds.contains( event.getPos() ) ) {
            behavior->controlRotation( true );
        } else {
            behavior->controlRotation( false );
        }
    }
     */
}

void TheSquareApp::mouseDrag( MouseEvent event )
{
}

void TheSquareApp::mouseUp( MouseEvent event )
{
}

void TheSquareApp::update()
{
    test->update();
}

void TheSquareApp::draw()
{
    gl::clear( Color( 0.177f, 0.177f, 0.177f ) );
    test->draw();
}

CINDER_APP_NATIVE( TheSquareApp, RendererGl )
