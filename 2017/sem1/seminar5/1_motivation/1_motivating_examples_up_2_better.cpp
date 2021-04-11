class VideoCodec
{
public:
	virtual ~VideoCodec() = default;

	bool can_decode(const std::string& filename) = 0;

	Video decode(const std::string& filename) = 0;
};


class VideoDecoder
{
public:
	VideoDecoder()
		: codecs_ {
			new VideoCodecDIVX(),
			new VideoCodecX264(),
			new VideoCodecXVID()}
	{}

	~VideoDecoder() noexcept
	{
		for (VideoCodec* codec : codecs_)
			delete codec;
	}

	Video Decode(const std::string& filename)
	{
		for (VideoCodec* codec : codecs_)
			if (codec->can_decode(filename))
				return codec->decode(filename);
		return Video();
	}

private:
	std::vector<VideoCodec*> codecs_;
};
