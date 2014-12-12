//
//  PdNode.h
//  pdtest
//
//  Created by Ilya Rostovtsev on 11/4/14.
//
//

#ifndef __pdtest__PdNode__
#define __pdtest__PdNode__

#pragma once

#include "PdBase.hpp"
#include "PdReceiver.hpp"
#include "PdTypes.hpp"

#include "cinder/audio/Node.h"
#include "cinder/Thread.h"

#include "SquareModel.h"

namespace cipd {
    
    typedef std::shared_ptr<pd::Patch> PatchRef;
    typedef std::shared_ptr<class PureDataNode> PureDataNodeRef;
    
    class PureDataNode : public ci::audio::Node {
    public:
        PureDataNode( const Format &format = Format() );
        ~PureDataNode();
        
        void initialize() override;
        void setModel( std::shared_ptr< SquareModel > model ) { mModel = model; }
        void uninitialize() override;
        void process( ci::audio::Buffer *buffer );
        
        pd::PdBase& getPd()	{ return mPdBase; }
        
        PatchRef	loadPatch( ci::DataSourceRef dataSource );
        void		closePatch( const PatchRef &patch );
        void        addToSearchPath( const std::string& path );
        
        // thread-safe senders
        void sendSquareBundle();
        
        void sendBang( const std::string& dest );
        void sendFloat( const std::string& dest, float value );
        void sendSymbol( const std::string& dest, const std::string& symbol );
        void sendList( const std::string& dest, const pd::List& list );
        void sendMessage( const std::string& dest, const std::string& msg, const pd::List& list = pd::List() );
        
        bool readArray( const std::string& arrayName, std::vector<float>& dest, int readLen = -1, int offset = 0 );
        bool writeArray( const std::string& arrayName, std::vector<float>& source, int writeLen = -1, int offset = 0 );
        void clearArray( const std::string& arrayName, int value = 0 );
        
    private:
        pd::PdBase	mPdBase;
        std::mutex	mMutex;
        size_t		mNumTicksPerBlock;
        
        ci::audio::BufferInterleaved mBufferInterleaved;
        
        std::shared_ptr< SquareModel > mModel;
        std::vector< std::string > mModelParams;
    };
    
} // namespace cipd

#endif /* defined(__pdtest__PdNode__) */
