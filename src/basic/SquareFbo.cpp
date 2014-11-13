//
//  SquareFbo.cpp
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#include "SquareFbo.h"

using namespace ci;
using namespace std;

SquareFbo::SquareFbo() { }

SquareFbo::SquareFbo( const std::string& resource_string, const Anim< float >* texture_rotation, const Anim< Vec2f >* scroll )
: texture_rotation_angle( texture_rotation ),
  texture_scroll( scroll )
{
    gl::Texture::Format fmt;
    fmt.setWrap( GL_REPEAT, GL_REPEAT );
    square_texture = gl::Texture { loadImage( app::loadResource( resource_string ) ), fmt };
    
    int size = min( app::getWindowWidth(), app::getWindowHeight() ) * 0.65f;
    float diagonal = sqrtf( 2.0f ) * size;
    dimensions = Vec2f{ diagonal, diagonal };
    texture_rect = Rectf{ -diagonal / 2.f, -diagonal / 2.f, diagonal / 2.f, diagonal / 2.f };
    square_fbo = gl::Fbo { size, size };
}

SquareFbo::~SquareFbo() { }

void SquareFbo::render()
{
    texture_sampler = Area( texture_scroll->operator const cinder::Vec2<float> &(), texture_scroll->operator const cinder::Vec2<float> &() + dimensions );
    
    square_fbo.bindFramebuffer();
    gl::clear( Color( Color::black() ) );
    gl::pushMatrices();
    gl::translate( square_fbo.getWidth() / 2.f, app::getWindowHeight() - square_fbo.getHeight() / 2.f );
    gl::rotate( *texture_rotation_angle );
    gl::color( 1.f, 1.f, 1.f );
    gl::draw( square_texture, texture_sampler, texture_rect );
    gl::popMatrices();
    square_fbo.unbindFramebuffer();
}