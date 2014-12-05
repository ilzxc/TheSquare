//
//  SquareAudio.h
//  TheSquare
//
//  Created by Husband :) on 11/16/14.
//
//

#ifndef __TheSquare__SquareAudio__
#define __TheSquare__SquareAudio__

#include <vector>
#include "cinder/audio/Context.h"
#include "PdNode.h"

class SquareAudio
{
  public:
    SquareAudio();
    ~SquareAudio();
    
    void setup(); // maybe unnecessary
    void update();
    
    void open_patches( const std::vector< std::string >& patch_names );
    void sendFloat( const float data, const std::string& inlet ) { }
    void sendBang( const std::string& inlet ) { }
    void sendList( const std::vector< float >& list, const std::string& inlet ) { }
    
  private:
    std::shared_ptr< cipd::PureDataNode > pd;
    std::vector< cipd::PatchRef > patches;
};

#endif /* defined(__TheSquare__SquareAudio__) */
