//
//  SquareObject.h
//  TheSquare
//
//  Created by Husband :) on 11/11/14.
//
//

#ifndef __TheSquare__SquareObject__
#define __TheSquare__SquareObject__

#include "SquareModel.h"
#include "SquareRender.h"
#include "SquareFbo.h"

class SquareObject
{
  public:
    SquareObject();
    SquareObject( const std::string& resource_string );
    ~SquareObject();
    
    void update();
    void draw();
    
    void interact();
    
    std::shared_ptr< SquareModel > getModel() { return model; }
    
  private:
    std::shared_ptr< SquareModel >  model;
    std::shared_ptr< SquareRender > view;
    
    int mode;
};

#endif /* defined(__TheSquare__SquareObject__) */
