//
//  PatchBay.cpp
//  TheSquare
//
//  Created by Husband :) on 11/17/14.
//
//

#include "PatchBay.h"

PatchBay::PatchBay()
{
    
}

PatchBay::~PatchBay()
{
    mModel.reset();
    mAudio.reset();
}


void PatchBay::update()
{
    for ( auto& pi : mModelParams )
    {
        switch ( pi.first ) {
            case SQUARE_ROTATION_ANGLE :
                mAudio->sendFloat( mModel->getSquareRotationAngle(), pi.second );
                break;
            case SQUARE_ROTATION_VELOCITY :
                mAudio->sendFloat( mModel->getSquareRotationVelocity(), pi.second );
                break;
            case SQUARE_ROTATION_ACCELERATION :
                mAudio->sendFloat( mModel->getSquareRotationAcceleration(), pi.second );
                break;
            case TEXTURE_ROTATION_ANGLE :
                mAudio->sendFloat( mModel->getTextureRotationAngle(), pi.second );
                break;
            case TEXTURE_ROTATION_VELOCITY :
                mAudio->sendFloat( mModel->getTextureRotationVelocity(), pi.second );
                break;
            case TEXTURE_ROTATION_ACCELERATION :
                mAudio->sendFloat( mModel->getTextureRotationAcceleration(), pi.second );
                break;
            case TEXTURE_SCROLL_POSITION :
                mAudio->sendFloat( mModel->getTextureScrollPosition().lengthSquared(), pi.second );
                break;
            case TEXTURE_SCROLL_VELOCITY :
                mAudio->sendFloat( mModel->getTextureScrollVelocity().lengthSquared(), pi.second );
                break;
            case TEXTURE_SCROLL_ACCELERATION :
                mAudio->sendFloat( mModel->getTextureScrollAcceleration().lengthSquared(), pi.second );
                break;
            default :
                break;
        }
    }
}

void PatchBay::connect( const std::vector< std::pair< int, std::string > >& param_inlet )
{
    mModelParams = param_inlet;
}

void PatchBay::disconnect( const std::string& inlet )
{
    
}

void PatchBay::disconnect( const int parameter )
{
    
}
