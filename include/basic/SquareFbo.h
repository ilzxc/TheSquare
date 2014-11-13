//
//  SquareFbo.h
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#ifndef __TheSquare__SquareFbo__
#define __TheSquare__SquareFbo__

#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Fbo.h"
#include "cinder/Timeline.h"

class SquareFbo
{
  public:
    SquareFbo();
    SquareFbo( const std::string& resource_string, const ci::Anim< float >* texture_rotation, const ci::Anim< ci::Vec2f >* scroll );
    ~SquareFbo();
    
    void render();
    inline ci::gl::Fbo &getFbo() { return square_fbo; }
    
  private:
    // data:
    ci::gl::Fbo square_fbo;
    ci::gl::Texture square_texture;
    
    // shared memory:
    const ci::Anim< float > *texture_rotation_angle;
    const ci::Anim< ci::Vec2f > *texture_scroll;
    
    // local
    ci::Vec2f dimensions;
    ci::Area texture_sampler;
    ci::Rectf texture_rect;
};

#endif /* defined(__TheSquare__SquareFbo__) */
