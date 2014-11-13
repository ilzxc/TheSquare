//
//  SquareController.h
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#ifndef __TheSquare__SquareController__
#define __TheSquare__SquareController__

#include "cinder/Vector.h"
#include "SquareModel.h"

enum {
    SQUARE,
    LEFT,
    RIGHT
};


class SquareController
{
  public:
    SquareController();
    ~SquareController();
    
    void bindModel( std::shared_ptr< SquareModel > modelRef );
    void mouseDown( const ci::Vec2f& position );
    void mouseDrag( const ci::Vec2f& position );
    void mouseUp( const ci::Vec2f& position );
    void update();
    
  private:
    bool touching, touched_square;
    ci::Vec2f started_touching;
    ci::Vec2f currently_touching;
    std::vector< ci::Rectf > regions;
    std::shared_ptr< SquareModel > modelRef;
    
    bool isInSquare();
    void rotateSquare();
    void scrollTexture();
    void rotateTexture();
};

#endif /* defined(__TheSquare__SquareController__) */
