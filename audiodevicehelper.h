#pragma once

namespace AudioDeviceHelper {
	class ADH {
	public:
		int setDefaultMicrophoneVolume(float nVolume);
		int getCurrentDefaultMicVolume();
	};
}

