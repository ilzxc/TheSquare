//
//  SquareAudio.cpp
//  TheSquare
//
//  Created by Husband :) on 11/16/14.
//
//

#include "SquareAudio.h"

using namespace ci;

SquareAudio::SquareAudio()
{
    auto context = audio::master();
    pd = context->makeNode( new cipd::PureDataNode( audio::Node::Format() ) );
    pd->enable();
    pd >> audio::master()->getOutput();
    context->enable();
}

SquareAudio::~SquareAudio()
{
    pd->disable();
    for ( auto patch : patches ) {
        pd->closePatch( patch );
    }
    
    auto context = audio::master();
    context->disable();
    context->disconnectAllNodes();
}


void SquareAudio::setup()
{
    // unnecessary?
}

void SquareAudio::update()
{
    
}

void SquareAudio::open_patches( const std::vector< std::string >& patch_names )
{
    pd->disable();
    for ( auto& patch : patch_names )
    {
        patches.push_back( pd->loadPatch( app::loadResource( patch ) ) );
    }
    pd->enable();
}