//
//  SquareObject.cpp
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#include "SquareObject.h"

using namespace std;

SquareObject::SquareObject()
: mode( 0 )
{
}

SquareObject::SquareObject( const std::string& resource_string )
: mode( 0 ),
  model { make_shared< SquareModel > () },
  view  { make_shared< SquareRender > ( model->getSquareRotationAnglePtr(), model->getOpacity() ) }
{
    shared_ptr< SquareFbo > to_bind = make_shared< SquareFbo > ( resource_string, model->getTextureRotationAnglePtr(), model->getTextureScrollPositionPtr() );
    view->bind_fbo( to_bind );
}

SquareObject::~SquareObject()
{
    
}

void SquareObject::interact()
{
    mode = 0;
}

void SquareObject::update()
{
    model->update();
    view->update();
    
    //model->setTextureScrollVelocity( ci::Vec2f( 50, 50 ), 500 );
    
    if ( mode == 0 ) {
        model->setSquareRotationVelocity( 3.0f, 20.f );
        ++mode;
    } else if ( mode == 1 ) {
        if ( model->getSquareRotationVelocity() >= 3.f ) {
            model->setSquareRotationAcceleration( 0.f );
            model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1.f, 20.f );
            ++mode;
        }
    } else if ( mode == 2 ) {
        if ( model->getTextureRotationVelocity() == model->getSquareRotationVelocity() * -1.f ) {
            //cout << "hit it" << endl;
            model->setSquareRotationVelocity( 0.f, 10.f );
            ++mode;
        }
    } else if ( mode == 3 ) {
        model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1 );
        if ( model->getSquareRotationVelocity() == 0.f ) {
            //cout << "yay" << endl;
            model->setSquareRotationVelocity( -3.02, 20.f );
            model->setTextureScrollVelocity( ci::Vec2f{ -0.8f, 0.9f } );
            ++mode;
        }
    } else if ( mode == 4 ) {
        model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1.f );
    }
}

void SquareObject::draw()
{
    view->draw();
}