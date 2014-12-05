//
//  SquareEvent.h
//  TheSquare
//
//  Created by Husband :) on 11/27/14.
//
//

#ifndef __TheSquare__SquareEvent__
#define __TheSquare__SquareEvent__

struct SquareEvent
{
    virtual bool forwardCondition() = 0;
    virtual void forwardAutomation() = 0;
};

#endif /* defined(__TheSquare__SquareEvent__) */
