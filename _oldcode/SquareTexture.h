//
//  SquareTexture.h
//  TheSquare
//
//  Created by Ilya Rostovtsev on 10/14/14.
//
//

#ifndef __TheSquare__SquareTexture__
#define __TheSquare__SquareTexture__

#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"

class SquareTexture
{
  public:
    SquareTexture();
    SquareTexture( const std::string& resource_string );
    SquareTexture( const SquareTexture& other );
    ~SquareTexture();
    void update();
    void draw();
    
    inline const ci::Vec2f& getDimensions() const { return dimensions; }
    
    inline void setSquareRotation( const float new_square_rotation_angle ) { rotation_angle = new_square_rotation_angle; }
    inline void setTextureRotation( const float new_texture_rotation ) { texture_rotation_velocity = new_texture_rotation; }
    inline void setSquareRotationVelocity( const float new_square_rotation_velocity ) { rotation_velocity = new_square_rotation_velocity; }
    inline void setTextureRotationVelocity( const float new_texture_rotation_velocity ) { texture_rotation_velocity = new_texture_rotation_velocity; }
    inline void setTextureScroll( const ci::Vec2f& new_scroll_position ) { scroll_position = new_scroll_position; }
    inline void setTextureScrollVelocity( const ci::Vec2f& new_scroll_velocity ) { scroll_velocity = new_scroll_velocity; }
    
    inline float getSquareRotation() { return rotation_angle; }
    inline float getTextureRotation() { return texture_rotation_angle; }
    inline float getSquareRotationVelocity() { return rotation_velocity; }
    inline float getTextureRotationVelocity() { return texture_rotation_velocity; }
    inline ci::Vec2f getTextureScroll() { return scroll_position; }
    inline ci::Vec2f getTextureScrollVelocity() { return scroll_velocity; }
    
    bool is_in( const ci::Vec2f& touch_position );
    void drag( const ci::Vec2f& touching );
    
  private:
    ci::gl::Texture square_texture;
    ci::gl::Fbo square_fbo;
    ci::Rectf square_rect, texture_rect, collision_rect;
    ci::Area texture_sample;
    ci::Vec2f dimensions;
    
    ci::Vec2f touch_started;
    float rotation_when_touch_started;
    ci::Vec2f touch_offset;
    
    float texture_rotation_angle;
    float texture_rotation_velocity;
    ci::Vec2f scroll_position;
    ci::Vec2f scroll_velocity;
    
    ci::Vec2f position;
    float rotation_angle;
    float rotation_velocity;
    
    ci::Vec2f corrected_touch( const ci::Vec2f& touch_position );
};

#endif /* defined(__TheSquare__SquareTexture__) */
