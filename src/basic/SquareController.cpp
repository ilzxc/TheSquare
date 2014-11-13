//
//  SquareController.cpp
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#include "SquareController.h"

SquareController::SquareController()
{
    
}

SquareController::~SquareController()
{
    
}


void SquareController::bindModel( std::shared_ptr< SquareModel > modelRef )
{
    
}

void SquareController::mouseDown( const ci::Vec2f& position )
{
    touching = true;
    if ( regions[ SQUARE ].contains( position ) ) {
        if ( isInSquare() ) {
            touched_square = true;
        }
    }
    started_touching = currently_touching = position;
}

void SquareController::mouseDrag( const ci::Vec2f& position )
{
    currently_touching = position;
}

void SquareController::mouseUp( const ci::Vec2f& position )
{
    touching = touched_square = false;
}

void SquareController::update()
{
    if ( touching ) {
        if ( touched_square ) {
            
        } else {

        }
    }
    
}

bool isInSquare()
{
    
}

void rotateSquare()
{
    
}

void scrollTexture()
{
    
}

void rotateTexture()
{
    
}
