//
//  SoundParam.h
//  TheSquare
//
//  Created by Husband :) on 11/16/14.
//
//

#ifndef __TheSquare__SoundParam__
#define __TheSquare__SoundParam__

#include "cinder/Timeline.h"

class Scale
{
public:
    Scale();
    Scale( const float in_input_low, const float in_input_high, const float in_output_low, const float in_output_high );
    ~Scale();
    
    float scale( const float input_value ) const;
    
private:
    float input_low, input_high, output_low, output_high;
    bool clip_edges;
};

#endif /* defined(__TheSquare__SoundParam__) */
