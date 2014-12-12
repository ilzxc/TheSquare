//
//  PdNode.cpp
//  pdtest
//
//  From PureDataNode Cinder Block by Richard Eakin
//
//

#include "PdNode.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/dsp/Converter.h"
#include "cinder/audio/Debug.h"

using namespace std;
using namespace ci;

namespace cipd {
    
    PureDataNode::PureDataNode( const Format &format )
    : Node( format )
    {
        if( getChannelMode() != ChannelMode::SPECIFIED ) {
            setChannelMode( ChannelMode::SPECIFIED );
            setNumChannels( 2 );
        }
        
        mModelParams.push_back( "sangle" );
        mModelParams.push_back( "sveloc" );
        mModelParams.push_back( "saccel" );
        
        mModelParams.push_back( "tangle" );
        mModelParams.push_back( "tveloc" );
        mModelParams.push_back( "taccel" );
        
        mModelParams.push_back( "tvectx" );
        mModelParams.push_back( "tvecty" );
        mModelParams.push_back( "tscvex" );
        mModelParams.push_back( "tscvey" );
        mModelParams.push_back( "tscacx" );
        mModelParams.push_back( "tscacy" );
        
        mModelParams.push_back( "opacit" );
    }
    
    PureDataNode::~PureDataNode()
    {
    }
    
    void PureDataNode::initialize()
    {
        mNumTicksPerBlock = getFramesPerBlock() / pd::PdBase::blockSize();
        
        if( getNumChannels() > 1 )
            mBufferInterleaved = audio::BufferInterleaved( getFramesPerBlock(), getNumChannels() );
        
        lock_guard< mutex > lock( mMutex );
        
        bool success = mPdBase.init( getNumChannels(), getNumChannels(), getSampleRate() );
        CI_ASSERT( success );
        
        // in libpd world, dsp computation is controlled through the process methods, so computeAudio is enabled until uninitialize
        mPdBase.computeAudio( true );
    }
    
    void PureDataNode::uninitialize()
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.computeAudio( false );
    }
    
    void PureDataNode::process( audio::Buffer *buffer )
    {
        if( getNumChannels() > 1 ) {
            audio::dsp::interleaveBuffer( buffer, &mBufferInterleaved );
            
            mMutex.lock();
            mPdBase.processFloat( mNumTicksPerBlock, mBufferInterleaved.getData(), mBufferInterleaved.getData() );
            mMutex.unlock();
            
            audio::dsp::deinterleaveBuffer( &mBufferInterleaved, buffer );
        }
        else {
            mMutex.lock();
            mPdBase.processFloat( mNumTicksPerBlock, buffer->getData(), buffer->getData() );
            mMutex.unlock();
        }
    }
    
    PatchRef PureDataNode::loadPatch( ci::DataSourceRef dataSource )
    {
        if( ! isInitialized() )
            getContext()->initializeNode( shared_from_this() );
        
        lock_guard< mutex > lock( mMutex );
        
        const fs::path& path = dataSource->getFilePath();
        pd::Patch patch = mPdBase.openPatch( path.filename().string(), path.parent_path().string() );
        if( ! patch.isValid() ) {
            CI_LOG_E( "could not open patch from dataSource: " << path );
            return PatchRef();
        }
        cout << patch << endl;
        return make_shared< pd::Patch >( patch );
    }
    
    void PureDataNode::closePatch( const PatchRef &patch )
    {
        if( ! patch )
            return;
        
        lock_guard< mutex > lock( mMutex );
        mPdBase.closePatch( *patch );
    }
    
    void PureDataNode::addToSearchPath( const std::string& path )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.addToSearchPath( path );
    }
    
    void PureDataNode::sendSquareBundle()
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendFloat( mModelParams[  0 ], mModel->getSquareRotationAngle()         );
        mPdBase.sendFloat( mModelParams[  1 ], mModel->getSquareRotationVelocity()      );
        mPdBase.sendFloat( mModelParams[  2 ], mModel->getSquareRotationAcceleration()  );
        
        mPdBase.sendFloat( mModelParams[  3 ], mModel->getTextureRotationAngle()        );
        mPdBase.sendFloat( mModelParams[  4 ], mModel->getTextureRotationVelocity()     );
        mPdBase.sendFloat( mModelParams[  5 ], mModel->getTextureRotationAcceleration() );
        
        mPdBase.sendFloat( mModelParams[  6 ], mModel->getTextureScrollPosition().x     );
        mPdBase.sendFloat( mModelParams[  7 ], mModel->getTextureScrollPosition().y     );
        
        mPdBase.sendFloat( mModelParams[  8 ], mModel->getTextureScrollVelocity().x     );
        mPdBase.sendFloat( mModelParams[  9 ], mModel->getTextureScrollVelocity().y     );
        
        mPdBase.sendFloat( mModelParams[ 10 ], mModel->getTextureScrollAcceleration().x );
        mPdBase.sendFloat( mModelParams[ 11 ], mModel->getTextureScrollAcceleration().y );        
    }
    
    
    void PureDataNode::sendBang( const std::string& dest )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendBang( dest );
    }
    
    void PureDataNode::sendFloat( const std::string& dest, float value )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendFloat( dest, value );
    }
    
    void PureDataNode::sendSymbol( const std::string& dest, const std::string& symbol )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendSymbol( dest, symbol );
    }
    
    void PureDataNode::sendList( const std::string& dest, const pd::List& list )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendList( dest, list );
    }
    
    void PureDataNode::sendMessage( const std::string& dest, const std::string& msg, const pd::List& list )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.sendMessage( dest, msg, list );
    }
    
    bool PureDataNode::readArray( const std::string& arrayName, std::vector<float>& dest, int readLen, int offset )
    {
        lock_guard< mutex > lock( mMutex );
        return mPdBase.readArray( arrayName, dest, readLen, offset );
    }
    
    bool PureDataNode::writeArray( const std::string& arrayName, std::vector<float>& source, int writeLen, int offset )
    {
        lock_guard< mutex > lock( mMutex );
        return mPdBase.writeArray( arrayName, source, writeLen, offset );
    }
    
    void PureDataNode::clearArray( const std::string& arrayName, int value )
    {
        lock_guard< mutex > lock( mMutex );
        mPdBase.clearArray( arrayName, value );
    }
    
} // namespace cipd

