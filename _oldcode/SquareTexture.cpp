//
//  SquareTexture.cpp
//  TheSquare
//
//  Created by Ilya Rostovtsev on 10/14/14.
//
//

#include "SquareTexture.h"

using namespace ci;
using namespace std;

SquareTexture::SquareTexture(){}

SquareTexture::SquareTexture( const string& resource_string )
: rotation_angle { 0.f },
  rotation_velocity { 0.f },
  scroll_position { 0.f, 0.f },
  scroll_velocity { 0.f, 0.f },
  texture_rotation_angle { 0.f },
  texture_rotation_velocity { 0.f }
{
    gl::Texture::Format fmt;
    fmt.setWrap( GL_REPEAT, GL_REPEAT );
    square_texture = gl::Texture( loadImage( app::loadResource( resource_string ) ), fmt );
    
    int size = min( app::getWindowWidth(), app::getWindowHeight() ) * 0.65f;
    float diagonal = sqrtf( 2.0f ) * size;

    square_fbo = gl::Fbo{ size, size };
    position = Vec2f{ app::getWindowCenter() };
    square_rect = Rectf{ -size / 2.f, size / 2.f, size / 2.f, -size / 2.f };                        // Vertical flip for FBO Texture
    collision_rect = Rectf{ -size / 2.f, -size / 2.f, size / 2.f, size / 2.f };
    texture_rect = Rectf{ -diagonal / 2.f, -diagonal / 2.f, diagonal / 2.f, diagonal / 2.f };
    dimensions = Vec2f{ diagonal, diagonal };
}

SquareTexture::SquareTexture( const SquareTexture& other )
{
}

SquareTexture::~SquareTexture()
{
    square_fbo.reset();
}

bool SquareTexture::is_in( const Vec2f& touch_position )
{
    Vec2f test = corrected_touch( touch_position );
    bool result = collision_rect.contains( test );
    if ( result ) {
        touch_started = test;
        touch_offset = touch_started - scroll_position;
    }
    return result;
}

void SquareTexture::drag( const ci::Vec2f& touching )
{
    Vec2f destination = touching * -1.f;
    scroll_position = destination - touch_started + touch_offset;
}

void SquareTexture::update()
{
    texture_rotation_angle += texture_rotation_velocity;
    rotation_angle += rotation_velocity;
    scroll_position += scroll_velocity;
    texture_sample = Area( scroll_position, scroll_position + dimensions );
    
    square_fbo.bindFramebuffer();
    gl::clear( Color( Color::black() ) );
    gl::pushMatrices();
    gl::translate( square_fbo.getWidth() / 2.f, app::getWindowHeight() - square_fbo.getHeight() / 2.f );
    gl::rotate( texture_rotation_angle );
    gl::color( 1.f, 1.f, 1.f );
    gl::draw( square_texture, texture_sample, texture_rect );
    gl::popMatrices();
    square_fbo.unbindFramebuffer();
}

void SquareTexture::draw()
{
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( rotation_angle );
    gl::color( 1.f, 1.f, 1.f );
    gl::draw( square_fbo.getTexture(), square_rect );
    gl::popMatrices();
}

Vec2f SquareTexture::corrected_touch( const ci::Vec2f& touch_position )
{
    Vec2f result = touch_position - position;
    result.rotate( toRadians( rotation_angle ) );
    return result;
}