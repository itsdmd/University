using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal class TV : BaseDevice
	{
		const uint CHN_MIN = 1;
		const uint CHN_MAX = 500;
		uint _channelMin = 1;
		uint _channelMax = 50;

		public TV()
		{
			_name = "TV";
			_channelNow = 1;
		}

		public override void SetChannel(uint channel)
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

		public override Dictionary<string, uint> GetLimits()
		{
			Dictionary<string, uint> limits = new Dictionary<string, uint>();
			limits.Add("CHN_MIN", CHN_MIN);
			limits.Add("CHN_MAX", CHN_MAX);
			limits.Add("CHN_STEP", 1);

			return limits;
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
	}
}
