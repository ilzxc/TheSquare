//
//  SquareModel.h
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#ifndef __TheSquare__SquareModel__
#define __TheSquare__SquareModel__

#include "cinder/Timeline.h"

class SquareModel
{
  public:
    SquareModel();
    ~SquareModel();
    
    inline const ci::Anim< float >      * getSquareRotationAnglePtr() { return &square_rotation_angle; }
    inline const ci::Anim< float >      * getTextureRotationAnglePtr() { return &texture_rotation_angle; }
    inline const ci::Anim< ci::Vec2f >  * getTextureScrollPositionPtr() { return &texture_scroll_position; }
    inline const ci::Anim< float >      * getOpacity() { return &opacity; }
    
    inline float getSquareRotationAngle() { return square_rotation_angle.operator const float &(); }
    inline float getSquareRotationVelocity() { return square_rotation_velocity.operator const float &(); }
    inline float getSquareRotationAcceleration() { return square_rotation_acceleration.operator const float &(); }
    inline float getTextureRotationAngle() { return texture_rotation_angle.operator const float &(); }
    inline float getTextureRotationVelocity() { return texture_rotation_velocity.operator const float &(); }
    inline float getTextureRotationAcceleration() { return texture_rotation_acceleration.operator const float &(); }
    inline ci::Vec2f getTextureScrollPosition() { return texture_scroll_position.operator const cinder::Vec2<float> &(); }
    inline ci::Vec2f getTextureScrollVelocity() { return texture_scroll_velocity.operator const cinder::Vec2<float> &(); }
    inline ci::Vec2f getTextureScrollAcceleration() { return texture_scroll_acceleration.operator const cinder::Vec2<float> &(); }

    inline void setSquareRotationAngle( const float new_angle ) { square_rotation_angle = new_angle; }
    inline void setSquareRotationVelocity( const float new_velocity ) { square_rotation_velocity = new_velocity; }
    inline void setSquareRotationAcceleration( const float new_acceleration ) { square_rotation_acceleration = new_acceleration; }
    inline void setTextureRotationAngle( const float new_angle ) { texture_rotation_angle = new_angle; }
    inline void setTextureRotationVelocity( const float new_velocity ) { texture_rotation_velocity = new_velocity; }
    inline void setTextureRotationAcceleration( const float new_acceleration ) { texture_rotation_acceleration = new_acceleration; }
    inline void setTextureScrollPosition( const ci::Vec2f& new_position ) { texture_scroll_position = new_position; }
    inline void setTextureScrollVelocity( const ci::Vec2f& new_velocity ) { texture_scroll_velocity = new_velocity; }
    inline void setTextureScrollAcceleration( const ci::Vec2f& new_acceleration ) { texture_scroll_acceleration = new_acceleration; }
    inline void setOpacity( const float new_opacity ) { opacity = new_opacity; }
    
    void setSquareRotationAngle( const float new_angle, const float time_in_seconds );
    void setSquareRotationVelocity( const float new_velocity, const float time_in_seconds );
    void setSquareRotationAcceleration( const float new_acceleration, const float time_in_seconds );
    void setTextureRotationAngle( const float new_angle, const float time_in_seconds );
    void setTextureRotationVelocity( const float new_velocity, const float time_in_seconds );
    void setTextureRotationAcceleration( const float new_acceleration, const float time_in_seconds );
    void setTextureScrollPosition( const ci::Vec2f& new_position, const float time_in_seconds );
    void setTextureScrollVelocity( const ci::Vec2f& new_velocity, const float time_in_seconds );
    void setTextureScrollAcceleration( const ci::Vec2f& new_acceleration, const float time_in_seconds );
    void setOpacity( const float new_opacity, const float time_in_seconds );
    
    void update();
    
  private:
    ci::Anim< float > square_rotation_angle;
    ci::Anim< float > square_rotation_velocity;
    ci::Anim< float > square_rotation_acceleration;
    ci::Anim< float > texture_rotation_angle;
    ci::Anim< float > texture_rotation_velocity;
    ci::Anim< float > texture_rotation_acceleration;
    ci::Anim< ci::Vec2f > texture_scroll_position;
    ci::Anim< ci::Vec2f > texture_scroll_velocity;
    ci::Anim< ci::Vec2f > texture_scroll_acceleration;
    ci::Anim< float > opacity;
    
    void setTween( ci::Anim< float >& which, const float new_value, const float time_in_seconds );
    void setTween( ci::Anim< ci::Vec2f >& which, const ci::Vec2f& new_value, const float time_in_seconds );
    
};

#endif /* defined(__TheSquare__SquareModel__) */
