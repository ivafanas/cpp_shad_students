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
			std::make_unique<VideoCodecDIVX>(),
			std::make_unique<VideoCodecX264>(),
			std::make_unique<VideoCodecXVID>()}
	{}

	~VideoDecoder() noexcept = default;

	Video Decode(const std::string& filename)
	{
		for (VideoCodec* codec : codecs_)
			if (codec->can_decode(filename))
				return codec->decode(filename);
		return Video();
	}

private:
	std::vector<std::unique_ptr<VideoCodec>> codecs_;
};
