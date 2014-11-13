//
//  SquareRender.h
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#ifndef __TheSquare__SquareRender__
#define __TheSquare__SquareRender__

#include "cinder/gl/gl.h"
#include "cinder/Timeline.h"
#include "SquareFbo.h"

class SquareRender
{
  public:
    SquareRender();
    SquareRender( const ci::Anim< float >* n_square_rotation_angle, const ci::Anim< float >* n_opacity );
    ~SquareRender();
    
    void bind_fbo( std::shared_ptr< SquareFbo > nFbo );
    void update();
    void draw();
    
  private:
    std::shared_ptr< SquareFbo > fbo;
    ci::Rectf square_rect;
    ci::Vec2f position;
    
    const ci::Anim< float > *square_rotation_angle;
    const ci::Anim< float > *opacity;
};

#endif /* defined(__TheSquare__SquareRender__) */
