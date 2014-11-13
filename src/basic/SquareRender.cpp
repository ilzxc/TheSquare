//
//  SquareRender.cpp
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#include "SquareRender.h"

using namespace ci;

SquareRender::SquareRender() { }

SquareRender::SquareRender( const ci::Anim< float >* n_square_rotation_angle, const ci::Anim< float >* n_opacity )
: position{ app::getWindowCenter() },
  square_rotation_angle( n_square_rotation_angle ),
  opacity( n_opacity ),
  square_rect( 0.f, 0.f, 0.f, 0.f )
{
    
}

SquareRender::~SquareRender()
{
    
}

void SquareRender::bind_fbo( std::shared_ptr< SquareFbo > nFbo )
{
    fbo = nFbo;
    int width = fbo->getFbo().getWidth();
    int height = fbo->getFbo().getHeight();
    square_rect = Rectf( width / -2.f, height / 2.f, width / 2.f, height / -2.f );
}

void SquareRender::update()
{
    fbo->render();    
}

void SquareRender::draw()
{
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( *square_rotation_angle );
    gl::color( 1.f, 1.f, 1.f, *opacity );
    gl::draw( fbo->getFbo().getTexture(), square_rect );
    gl::popMatrices();
}