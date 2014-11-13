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
: model { make_shared< SquareModel > () },
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
//    model->setTextureRotationAcceleration( 0.0005f, 100.f );
//    model->setTextureScrollAcceleration( ci::Vec2f{ -0.2, 0.29 }, 20.f );
}

void SquareObject::update()
{
    if ( mode == 0 ) {
        model->setSquareRotationVelocity( 3.0f, 20.f );
        ++mode;
    } else if ( mode == 1 ) {
        if ( model->getSquareRotationVelocity() >= 3.f ) {
            model->setSquareRotationAcceleration( 0.f );
            model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1.f, 10.f );
            ++mode;
        }
    } else if ( mode == 2 ) {
        if ( model->getTextureRotationVelocity() == model->getSquareRotationVelocity() * -1.f ) {
            cout << "hit it" << endl;
            model->setSquareRotationVelocity( 0.f, 10.f );
            ++mode;
        }
    } else if ( mode == 3 ) {
        model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1 );
        if ( model->getSquareRotationVelocity() == 0.f ) {
            cout << "yay" << endl;
            model->setSquareRotationAcceleration( -0.02, 20.f );
            model->setTextureScrollAcceleration( ci::Vec2f{ -0.001f, 0.001f }, 20.f );
            ++mode;
        }
    } else if ( mode == 4 ) {
        model->setTextureRotationVelocity( model->getSquareRotationVelocity() * -1 );
    }
    
    model->update();
    view->update();
}

void SquareObject::draw()
{
    view->draw();
}