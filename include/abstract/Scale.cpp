//
//  Scale.cpp
//  TheSquare
//
//  Created by Husband :) on 11/16/14.
//
//

#include "Scale.h"

Scale::Scale()
: input_low( 0.f ),
  input_high( 1.f ),
  output_low( 0.f ),
  output_high( 1.f )
{
    
}

Scale::Scale( const float in_input_low, const float in_input_high, const float in_output_low, const float in_output_high )
: input_low( in_input_low ),
  input_high( in_input_high ),
  output_low( in_output_low ),
  output_high( in_output_high )
{
    
}

Scale::~Scale()
{
}

float Scale::scale( const float input_value ) const
{
    float input_range  = input_high - input_low;
    float output_range = output_high - output_low;
    
    if ( input_range == 0 )
        return output_low;

    float ratio = output_range / input_range;
    return ( input_value - input_low ) * ratio + output_low;
    
}