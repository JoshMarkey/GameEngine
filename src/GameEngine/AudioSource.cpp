#include "AudioSource.h"
#include "stb_vorbis.c"
namespace myengine
{
void AudioSource::onLoad(std::string _path)
{
	path = _path;
	maxTime = 5;
	timer = 0;
	ALenum format = 0;
	ALsizei freq = 0;
	std::vector<unsigned char> bufferData;
	load_ogg(_path, bufferData, format, freq);

	ALuint bufferId = 0;
	alGenBuffers(1, &bufferId);

	alBufferData(bufferId, format, &bufferData.at(0),
		static_cast<ALsizei>(bufferData.size()), freq);

	m_sourceId = 0;
	alGenSources(1, &m_sourceId);

	alSourcei(m_sourceId, AL_BUFFER, bufferId);
	//alSourcePlay(sourceId);
}

void AudioSource::play()
{
	if (m_sourceId)
	{
		timer = 0;
		alSourcePlay(m_sourceId);
	}
}

ALuint AudioSource::getId()
{
	return m_sourceId;
}

//Load .ogg files
void AudioSource::load_ogg(const std::string & _path, std::vector<unsigned char>&_buffer, ALenum & _format, ALsizei & _freq)
{
	int channels = 0;
	int sampleRate = 0;
	short* output = NULL;

	size_t samples = stb_vorbis_decode_filename(_path.c_str(),
		&channels, &sampleRate, &output);

	if (samples == -1)
	{
		throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
	}

	// Record the format required by OpenAL
	if (channels < 2)
	{
		_format = AL_FORMAT_MONO16;
	}
	else
	{
		_format = AL_FORMAT_STEREO16;
	}

	// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
	_buffer.resize(samples * channels * sizeof(short));
	memcpy(&_buffer.at(0), output, _buffer.size());

	// Record the sample rate required by OpenAL
	_freq = sampleRate;

	// Clean up the read data
	free(output);
}
//Clear source and buffer
AudioSource::~AudioSource()
{
	alDeleteSources(1, &m_sourceId);
	alDeleteBuffers(1, &m_bufferId);
} }
