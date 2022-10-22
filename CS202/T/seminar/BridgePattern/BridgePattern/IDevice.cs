using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal interface IDevice
	{
		void SetName(string name);
		string GetName();
		bool IsEnabled();
		void Enable();
		void Disable();
		uint GetVolume();
		void SetVolume(uint percent);
		uint GetChannel();
		void SetChannel(uint channel);
		string GetMode();
		void SetMode(string mode);
		Dictionary<string, uint> GetLimits();
		void Log(string message);
	}

	internal class TV : IDevice
	{
		string _name = "TV";
		bool _powerState = false;
		uint _volume = 0;
		const uint CHN_MIN = 1;
		const uint CHN_MAX = 500;
		uint _channelNow = 1;
		uint _channelMin = 1;
		uint _channelMax = 50;

		public TV() { }

		public void SetName(string name)
		{
			_name = name;
			Log("TV's name is set to \"" + _name + "\".");
		}

		public string GetName()
		{
			return _name;
		}

		public void Disable()
		{
			_powerState = false;
			Log("Turned off");
		}

		public void Enable()
		{
			_powerState = true;
			Log("Turned on");
		}

		public bool IsEnabled()
		{
			return _powerState;
		}

		public uint GetChannel()
		{
			return (uint)_channelNow;
		}

		public uint GetVolume()
		{
			return (uint)_volume;
		}

		public void SetChannel(uint channel)
		{
			if (channel < _channelMin)
			{
				channel = _channelMin;
			}
			else if (channel > _channelMax)
			{
				channel = _channelMax;
			}

			_channelNow = channel;
			Log("Channel set to " + _channelNow);
		}

		public void SetVolume(uint percent)
		{
			if (percent < 0)
			{
				percent = 0;
			}
			else if (percent > 100)
			{
				percent = 100;
			}

			_volume = percent;
			Log("Volume set to " + _volume + "%");
		}

		public Dictionary<string, uint> GetLimits()
		{
			Dictionary<string, uint> limits = new Dictionary<string, uint>();
			limits.Add("CHN_MIN", CHN_MIN);
			limits.Add("CHN_MAX", CHN_MAX);
			limits.Add("CHN_STEP", 1);

			return limits;
		}

		public void Log(string message)
		{
			Console.WriteLine($"{_name}: {message}");
		}

		public override string ToString()
		{
			return ("Device Type: TV"
					+ "\nName: " + _name
					+ "\nPower: " + (_powerState ? "On" : "Off")
					+ "\nVolume: " + _volume
					+ "\nChannel: " + _channelNow
					+ "\nChannel Min: " + _channelMin
					+ "\nChannel Max: " + _channelMax);
		}

		public string GetMode()
		{
			return "";
		}

		public void SetMode(string mode)
		{
			return;
		}
	}

	internal class Radio : IDevice
	{
		string _name = "Radio";
		bool _powerState = false;
		bool _isFM = true;
		uint _volume = 0;
		public const uint AM_MIN = 520;
		public const uint AM_MAX = 1610;
		public const uint AM_STEP = 10;
		public const uint FM_MIN = 87000;
		public const uint FM_MAX = 108000;
		public const uint FM_STEP = 200;
		uint _frequencyNow = 100000;
		uint _frequencyMin = FM_MIN;
		uint _frequencyMax = FM_MAX;

		public Radio() { }

		public void SetName(string name)
		{
			_name = name;
			Log("Radio's name is set to \"" + _name + "\".");
		}

		public string GetName()
		{
			return _name;
		}

		public void Disable()
		{
			_powerState = false;
			Log("Turned off");
		}

		public void Enable()
		{
			_powerState = true;
			Log("Turned on");
		}

		public bool IsEnabled()
		{
			return _powerState;
		}

		public uint GetChannel()
		{
			return (uint)_frequencyNow;
		}

		public uint GetVolume()
		{
			return (uint)_volume;
		}

		public void SetChannel(uint frequency)
		{
			if (frequency < _frequencyMin)
			{
				frequency = _frequencyMin;
			}
			else if (frequency > _frequencyMax)
			{
				frequency = _frequencyMax;
			}

			_frequencyNow = frequency;
			Log("Frequency set to " + _frequencyNow);
		}

		public void SetVolume(uint percent)
		{
			if (percent < 0)
			{
				percent = 0;
			}
			else if (percent > 100)
			{
				percent = 100;
			}

			_volume = percent;
			Log("Volume set to " + _volume + "%");
		}

		public string GetMode()
		{
			if (_isFM)
			{
				return "FM";
			}
			else
			{
				return "AM";
			}
		}

		public void SetMode(string mode)
		{
			if (mode == "FM")
			{
				_isFM = true;
				_frequencyMin = FM_MIN;
				_frequencyMax = FM_MAX;
				Log("Mode set to FM.");
			}
			else if (mode == "AM")
			{
				_isFM = false;
				_frequencyMin = AM_MIN;
				_frequencyMax = AM_MAX;
				Log("Mode set to AM.");
			}
			else
			{
				Log("Unknown mode. Current mode is " + GetMode());
			}
		}

		public Dictionary<string, uint> GetLimits()
		{
			Dictionary<string, uint> limits = new Dictionary<string, uint>();

			if (_isFM)
			{
				limits.Add("CHN_MIN", FM_MIN);
				limits.Add("CHN_MAX", FM_MAX);
				limits.Add("CHN_STEP", FM_STEP);
			}
			else
			{
				limits.Add("CHN_MIN", AM_MIN);
				limits.Add("CHN_MAX", AM_MAX);
				limits.Add("CHN_STEP", AM_STEP);
			}

			return limits;
		}

		public void Log(string message)
		{
			Console.WriteLine($"{_name}: {message}");
		}

		public override string ToString()
		{
			return ("Device Type: Radio"
					+ "\nName: " + _name
					+ "\nPower: " + (_powerState ? "On" : "Off")
					+ "\nVolume: " + _volume
					+ "\nMode: " + (_isFM ? "FM" : "AM")
					+ "\nFrequency: " + _frequencyNow
					+ "\nFrequency Min: " + _frequencyMin
					+ "\nFrequency Max: " + _frequencyMax);
		}
	}
}
