#ifndef ROSNEURO_ACQUISITION_PLUGIN_LSLDEVICE_HPP
#define ROSNEURO_ACQUISITION_PLUGIN_LSLDEVICE_HPP

#include <errno.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <regex>
#include <limits>
#include <lsl_cpp.h>
#include <pluginlib/class_list_macros.h>
#include <rosneuro_data/NeuroData.hpp>
#include <rosneuro_acquisition/Device.hpp>

namespace rosneuro {

class LSLDevice : public Device {

	public:
		LSLDevice(void);
		LSLDevice(NeuroFrame* frame);
		virtual ~LSLDevice(void);

		bool Setup(float framerate);
		bool Open(const std::string& devname, int samplerate);
		bool Close(void);
		bool Start(void);
		bool Stop(void);
		size_t Get(void);
		size_t GetAvailable(void);

	private:
		void destroy_lsl_structures(void);
		std::vector<std::string> escape_device_string(const std::string& devarg, 
													  const std::string& delimiter);

	private:
		lsl::stream_inlet* stream_;
		lsl::stream_info*  info_;

		std::string		stream_name_;
		std::string		stream_type_;
};


PLUGINLIB_EXPORT_CLASS(rosneuro::LSLDevice, rosneuro::Device)

}



#endif
