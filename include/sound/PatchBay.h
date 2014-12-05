//
//  PatchBay.h
//  TheSquare
//
//  Created by Husband :) on 11/17/14.
//
//

#ifndef __TheSquare__PatchBay__
#define __TheSquare__PatchBay__

#include "SquareModel.h"
#include "SquareAudio.h"

class PatchBay
{
public:
    PatchBay();
    ~PatchBay();
    
    void update();
    void connect( const std::vector< std::pair< int, std::string > >& param_inlet );
    void disconnect( const std::string& inlet );
    void disconnect( const int parameter );
    
    enum floatParameters {
        SQUARE_ROTATION_ANGLE = 0,
        SQUARE_ROTATION_VELOCITY,
        SQUARE_ROTATION_ACCELERATION,
        TEXTURE_ROTATION_ANGLE,
        TEXTURE_ROTATION_VELOCITY,
        TEXTURE_ROTATION_ACCELERATION
    };
    
    enum vectorParameters {
        TEXTURE_SCROLL_POSITION = 6,
        TEXTURE_SCROLL_VELOCITY,
        TEXTURE_SCROLL_ACCELERATION
    };
    
private:
    std::shared_ptr< SquareModel > mModel;
    std::shared_ptr< SquareAudio > mAudio;
    std::vector< std::pair< int, std::string > > mModelParams;
};

#endif /* defined(__TheSquare__PatchBay__) */
