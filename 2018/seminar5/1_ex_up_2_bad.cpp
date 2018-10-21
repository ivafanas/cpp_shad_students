class VideoCodec
{
public:
	virtual ~VideoCodec() = default;

	virtual bool can_decode(const std::string& filename) = 0;

	virtual Video decode(const std::string& filename) = 0;
};

class VideoDecoder
{
public:
	VideoDecoder()
		: codecs_{
			new VideoCodecDIVX(),
			new VideoCodecX264(),
			new VideoCodecXVID()}
	{}

	~VideoDecoder() {
		for (auto codec: codecs_)
			delete codec;
	}

	Video Decode(const std::string& filename)
	{
		for (auto& codec : codecs_)
			if (codec->can_decode(filename))
				return codec->decode(filename);
		return Video();
	}

private:
	std::vector<VideoCodec*> codecs_;
};
