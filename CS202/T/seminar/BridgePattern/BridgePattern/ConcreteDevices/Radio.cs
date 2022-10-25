using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal class Radio : BaseDevice
	{
		bool _isFM = true;
		public const uint AM_MIN = 520;
		public const uint AM_MAX = 1610;
		public const uint AM_STEP = 10;
		public const uint FM_MIN = 87000;
		public const uint FM_MAX = 108000;
		public const uint FM_STEP = 200;
		uint _channelMin = FM_MIN;
		uint _channelMax = FM_MAX;
		
		public Radio()
		{
			_name = "Radio";
			_channelNow = 100000;
		}

		public override void SetChannel(uint frequency)
		{
			if (frequency < _channelMin)
			{
				frequency = _channelMin;
			}
			else if (frequency > _channelMax)
			{
				frequency = _channelMax;
			}

			_channelNow = frequency;
			Log("Frequency set to " + _channelNow);
		}

		public override string GetMode()
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

		public override void SetMode(string mode)
		{
			if (mode == "FM")
			{
				_isFM = true;
				_channelMin = FM_MIN;
				_channelMax = FM_MAX;
				Log("Mode set to FM.");
			}
			else if (mode == "AM")
			{
				_isFM = false;
				_channelMin = AM_MIN;
				_channelMax = AM_MAX;
				Log("Mode set to AM.");
			}
			else
			{
				Log("Unknown mode. Current mode is " + GetMode());
			}
		}

		public override Dictionary<string, uint> GetLimits()
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

		public override string ToString()
		{
			return ("Device Type: Radio"
					+ "\nName: " + _name
					+ "\nPower: " + (_powerState ? "On" : "Off")
					+ "\nVolume: " + _volume
					+ "\nMode: " + (_isFM ? "FM" : "AM")
					+ "\nFrequency: " + _channelNow
					+ "\nFrequency Min: " + _channelMin
					+ "\nFrequency Max: " + _channelMax);
		}
	}
}
