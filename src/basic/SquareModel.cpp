//
//  SquareModel.cpp
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#include "SquareModel.h"

using namespace ci;

SquareModel::SquareModel()
: square_rotation_angle { 0.f },
  square_rotation_velocity { 0.f },
  square_rotation_acceleration{ 0.f },
  texture_rotation_angle { 0.f },
  texture_rotation_velocity { 0.f },
  texture_rotation_acceleration{ 0.f },
  texture_scroll_position { Vec2f::zero() },
  texture_scroll_velocity { Vec2f::zero() },
  opacity( 1.f )
{
    
}

SquareModel::~SquareModel() { }

/*
void SquareModel::setTextureRotationAcceleration( const float new_acceleration, const float time_in_seconds )
{
    ci::app::timeline().apply( &texture_rotation_acceleration,
                                texture_rotation_acceleration.operator const float &(),
                                new_acceleration,
                                time_in_seconds,
                                EaseInOutCubic() );
}
 */

void SquareModel::setSquareRotationAngle( const float new_angle, const float time_in_seconds )
{
    setTween( square_rotation_angle, new_angle, time_in_seconds );
}

void SquareModel::setSquareRotationVelocity( const float new_velocity, const float time_in_seconds )
{
    setTween( square_rotation_velocity, new_velocity, time_in_seconds );
}

void SquareModel::setSquareRotationAcceleration( const float new_acceleration, const float time_in_seconds )
{
    setTween( square_rotation_acceleration, new_acceleration, time_in_seconds );
}

void SquareModel::setTextureRotationAngle( const float new_angle, const float time_in_seconds )
{
    setTween( texture_rotation_angle, new_angle, time_in_seconds );
}

void SquareModel::setTextureRotationVelocity( const float new_velocity, const float time_in_seconds )
{
    setTween( texture_rotation_velocity, new_velocity, time_in_seconds );
}

void SquareModel::setTextureRotationAcceleration( const float new_acceleration, const float time_in_seconds )
{
    setTween( texture_rotation_acceleration, new_acceleration, time_in_seconds );
}

void SquareModel::setTextureScrollPosition( const Vec2f& new_position, const float time_in_seconds )
{
    setTween( texture_scroll_position, new_position, time_in_seconds );
}

void SquareModel::setTextureScrollVelocity( const Vec2f& new_velocity, const float time_in_seconds )
{
    setTween( texture_scroll_velocity, new_velocity, time_in_seconds );
}

void SquareModel::setTextureScrollAcceleration( const Vec2f& new_acceleration, const float time_in_seconds )
{
    setTween( texture_scroll_acceleration, new_acceleration, time_in_seconds );
}

void SquareModel::setOpacity( const float new_opacity, const float time_in_seconds )
{
    setTween( square_rotation_angle, new_opacity, time_in_seconds );
}

void SquareModel::update()
{
    square_rotation_velocity = square_rotation_velocity.operator const float &() + square_rotation_acceleration.operator const float &();
    square_rotation_angle = square_rotation_angle.operator const float &() + square_rotation_velocity.operator const float &();
    
    texture_rotation_velocity = texture_rotation_velocity.operator const float &() + texture_rotation_acceleration.operator const float &();
    texture_rotation_angle = texture_rotation_angle.operator const float &() + texture_rotation_velocity.operator const float &();
    
    texture_scroll_velocity = texture_scroll_velocity.operator const cinder::Vec2<float> &() + texture_scroll_acceleration.operator const cinder::Vec2<float> &();
    if ( texture_scroll_velocity.operator()().lengthSquared() > 20.f ) {
        texture_scroll_velocity.operator()().limit( 20.f );
    }
    texture_scroll_position = texture_scroll_position.operator const cinder::Vec2<float> &() + texture_scroll_velocity.operator const cinder::Vec2<float> &();
}



void SquareModel::setTween( Anim< float >& which, const float new_value, const float time_in_seconds )
{
    
    auto test = app::timeline().apply( &which,
                            which.operator const float &(),
                            new_value,
                            time_in_seconds,
                            EaseInOutCubic() );
}

void SquareModel::setTween( Anim< Vec2f >& which, const Vec2f& new_value, const float time_in_seconds )
{
    app::timeline().apply( &which,
                            which.operator const ci::Vec2< float > &(),
                            new_value,
                            time_in_seconds,
                            EaseInOutCubic() );
    
}